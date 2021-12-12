#ifndef CHAR_HPP_INCLUDED
#define CHAR_HPP_INCLUDED


class Char{
	public:
		// Variaveis----------------
		// Instancia a Textura
		sf::Texture texture;
		// Instancia Sprite
		sf::Sprite sprite;
		// Corresponde a posição do objeto
		Position position;
		// vetor de direção de aceleração
		Position vector_move;

		Proportion proportion;
		// Funções------------------
		// Retorna sprites
		sf::Sprite drawSP();
		// Retorna a posição do player
		sf::Vector2f getPositionCenter();
		// Configura posição
		void setPosition(int x, int y);
		// Modifiica a area visualizavel da imagem
		void setShowArea(int x,int y,int w,int h);
		// Configura o sprite e a textura
		void setSpriteTexture(std::string texture_path);

};

// Chama pra desenhar
inline sf::Sprite Char::drawSP(){ 
	return sprite; 
}

// Posição do player
inline sf::Vector2f Char::getPositionCenter(){ 
	return sf::Vector2f(position.x,position.y);
}

// Configura a posição do sprite
void Char::setPosition(int x,int y){
	position.x=x;
	position.y=y;
	sprite.setPosition(position.x,position.y); 
}

// Configura area que ira ser mostrada
inline void Char::setShowArea(int x,int y,int w,int h){ 
	sprite.setTextureRect(sf::IntRect(x,y,w,h)); 
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

#endif // CHAR_HPP_INCLUDED