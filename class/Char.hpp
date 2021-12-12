#ifndef CHAR_HPP_INCLUDED
#define CHAR_HPP_INCLUDED


class Char:public Node2D{
	public:
		// Variables-------------------------------
		// Instancia a Textura
		sf::Texture texture;
		// Instancia Sprite
		sf::Sprite sprite;
		// Diz respeito a proporção de um sprite
		Proportion proportion;
		// Function-------------------------------
		// Retorna sprites
		sf::Sprite drawSP();
		// Configura o sprite e a textura
		void setSpriteTexture(std::string texture_path);
		// Modifiica a area visualizavel da imagem
		void setShowArea(int x,int y);
		// Configura a posição do sprite
		inline void setPositionChar(float x,float y);
};		

// Configura a posição do sprite
inline void Char::setPositionChar(float x,float y){
	sprite.setPosition(x+position.x,y+position.y); 
}

// Chama pra desenhar
inline sf::Sprite Char::drawSP(){ 
	return sprite; 
}
// Configura area que ira ser mostrada
inline void Char::setShowArea(int x,int y){ 
	sprite.setTextureRect(sf::IntRect(x,y,x+proportion.width,y+proportion.height)); 
}

// Configura o sprite e a textura
void Char::setSpriteTexture(std::string texture_path){
	// Carrega a textura
	texture.loadFromFile(texture_path);
	// Coloca a testura no sprite
	sprite.setTexture(texture);
	// Configura proportion
	proportion.width=texture.getSize().x;
	proportion.height=texture.getSize().y;
	// configura o sprite no rect
	sprite.setTextureRect(sf::IntRect(0,0,proportion.width,proportion.height));

}


#endif