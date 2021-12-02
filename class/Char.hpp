#ifndef CHAR_HPP_INCLUDED
#define CHAR_HPP_INCLUDED


class Char{
	public:
		// Class de Aninhamento-----
		class Colision2D{
			public:
				// Variavies---------------------------------------
				// Posição global
				Box point;
				// Position margins
				Box margin;
				// Function------------------------------------------
				// Dectecta se há colisão com a caixa passada por parametro
				bool colide(Box pt){
					return (
						point.topX<pt.bottomX and
						point.bottomX>pt.topX and
						point.topY<pt.bottomY and
						point.bottomY>pt.topY
						)?true:false;
				};

				void setMargins(float x,float y,float w,float h){
					margin.topY=x;
					margin.topX=y;
					margin.bottomX=w;
					margin.bottomY=h;
				}

				// Configura as posições
				void setPositionColide(float Ox,float Oy,float Ow,float Oh){
						point.topX=Ox+margin.topX;
						point.topY=Oy+margin.topY;
						point.bottomX=Ow+margin.bottomX;
						point.bottomY=Oh+margin.bottomY;
				};
		};

		// Variaveis----------------
		// Instancia a Textura
		sf::Texture texture;
		// Instancia Sprite
		sf::Sprite sprite;
		// Corresponde a posição do objeto
		Position position;
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