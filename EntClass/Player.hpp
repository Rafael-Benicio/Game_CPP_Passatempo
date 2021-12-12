#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player:public Char{
	public:
		// Variavel------------------------------
		float aceleration;
		Colision2D colision;
		// Function -----------------------------
		// Butões apertados e reações
		void eventButtons(sf::Event *event);
		// Checa se ouve colisão dura
		void hardColision(Box *boxArray, int boxArrayLength);
		// Valores que seram atualizando internamente a cada chamada
		void processElements();
		// Constructor --------------------------
		// Instancia a imagen, a posição e a velocidade
		Player(std::string texture_path,float posX,float posY,float velocity);

};
// Butões apertados e reações
void Player::eventButtons(sf::Event *event){
	vector_move.x=0;
	vector_move.y=0;
	if (event->type==sf::Event::KeyPressed){
        if (event->key.code==sf::Keyboard::Left ) vector_move.x=-1;
		if (event->key.code==sf::Keyboard::Right ) vector_move.x=1;
        if (event->key.code==sf::Keyboard::Up ) vector_move.y=-1;
        if (event->key.code==sf::Keyboard::Down ) vector_move.y=1;
    } 
}
// Checa se ouve colisão dura
void Player::hardColision(Box *boxArray, int boxArrayLength){

    for (int i=0;i<boxArrayLength;i++){
        if (colision.point.topX==boxArray[i].topX &&  
        	colision.point.topY==boxArray[i].topY)
        {
        	continue;
        }else if (colision.colide(boxArray[i])){
        	float resetPositionX=0;
        	float resetPositionY=0;
			
			float Rs=boxArray[i].topX -colision.point.bottomX;
			float Es=colision.point.topX- boxArray[i].bottomX;

			float Bs=boxArray[i].topY- colision.point.bottomY;
			float Cs=colision.point.topY- boxArray[i].bottomY;

			if (((Rs>Es)?Rs:Es)>((Cs>Bs)?Cs:Bs))
				resetPositionX=(Rs>Es)?Rs:Es*-1;
			else
				resetPositionY=(Cs>Bs)?Cs*-1:Bs;

			setPosition((position.x+resetPositionX),(position.y+resetPositionY));
        }
    }
}
// Valores que seram atualizando internamente a cada chamada
void Player::processElements(){
	setPosition(position.x+aceleration*vector_move.x,position.y+aceleration*vector_move.y);
	setPosition(position.x,position.y+1);
	colision.setPositionColide(position.x,position.y,position.x+proportion.width,position.y+proportion.height);
}
// Instancia a imagen, a posição e a velocidade
Player::Player(std::string texture_path,float posX,float posY,float velocity){
	setSpriteTexture(texture_path);
	setPosition(posX,posY);
	aceleration=velocity;
}


#endif