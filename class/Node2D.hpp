#ifndef NODE2D_HPP_INCLUDED
#define NODE2D_HPP_INCLUDED


class Node2D{
	public:
		// Variaveis----------------
		// Corresponde a posição do objeto
		Position position;
		// Funções------------------
		// Retorna a posição do player
		sf::Vector2f getPositionCenter();
		// Configura posição
		void setPosition(int x, int y);

};

// Posição do player
inline sf::Vector2f Node2D::getPositionCenter(){ 
	return sf::Vector2f(position.x,position.y);
}

// Configura a posição do sprite
void Node2D::setPosition(int x,int y){
	position.x=x;
	position.y=y;
}


#endif // CHAR_HPP_INCLUDED