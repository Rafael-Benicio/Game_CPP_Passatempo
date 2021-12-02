#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player:public Char{
	public:
		// Variavel------------------------------
		float vel;
		Colision2D colision;
		// Function -----------------------------
		// Butões apertados e reações
		void eventButtons(sf::Event *event);
		// Checa se ouve colisão dura
		void hardColision(Box *boxArray, int boxArrayLength);
		// Valores que seram atualizando internamente a cada chamada
		void updateElements();
		// Constructor --------------------------
		// Instancia a imagen, a posição e a velocidade
		Player(std::string texture_path,float posX,float posY,float velocity);

};

void Player::eventButtons(sf::Event *event){
	vector_move.x=0;
	vector_move.y=0;
	if (event->type==sf::Event::KeyPressed){
        if (event->key.code==sf::Keyboard::Left) vector_move.x=-1;
		else if (event->key.code==sf::Keyboard::Right) vector_move.x=1;
        else if (event->key.code==sf::Keyboard::Up) vector_move.y=-1;
        else if (event->key.code==sf::Keyboard::Down) vector_move.y=1;
    } 
}

void Player::hardColision(Box *boxArray, int boxArrayLength){
    for (int i=0;i<boxArrayLength;i++){
        if (colision.colide(boxArray[i]) &&
        	colision.point.topX!=boxArray[i].topX &&
        	colision.point.topY!=boxArray[i].topY &&
        	colision.point.bottomX!=boxArray[i].bottomX &&
        	colision.point.bottomY!=boxArray[i].bottomY 
        ){
            vector_move.x*=-1;
			vector_move.y*=-1;
        }
    }
}

void Player::updateElements(){
	setPosition(position.x+vel*vector_move.x,position.y+vel*vector_move.y);
	colision.setPositionColide(position.x,position.y,position.x+proportion.width,position.y+proportion.height);
}

Player::Player(std::string texture_path,float posX,float posY,float velocity){
	setSpriteTexture(texture_path);
	setPosition(posX,posY);
	vel=velocity;
}


#endif