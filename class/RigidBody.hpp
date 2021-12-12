#ifndef RIGIDBODY_HPP_INCLUDED
#define RIGIDBODY_HPP_INCLUDED

class RigidBody:public Node2D{
	public:
		// Variavel------------------------------
		// Se vai ser capaz de colidir
		bool colideON;
		// Cria classe sprite
		Char sprite;

		Colision2D colision;
		// Function -----------------------------
		// Checa se ouve colisão dura
		void hardColision(Box *boxArray, int boxArrayLength);
		// Valores que seram atualizando internamente a cada chamada
		void processElements();
		// Adiministra o deslocamento do objeto
		inline void MoveAndSlide(float acelerationX,float acelerationY);
		// Constructor --------------------------
		// Instancia a imagen, a posição e a velocidade
		RigidBody(std::string texture_path,float posX,float posY);
		// Instancia com posição
		RigidBody(float posX,float posY);
		// Instancia vazia
		RigidBody();
};

// Checa se ouve colisão dura
void RigidBody::hardColision(Box *boxArray, int boxArrayLength){

    for (int i=0;i<boxArrayLength;i++){
        if (colision.point.topX==boxArray[i].topX &&  
        	colision.point.topY==boxArray[i].topY)
        {
        	continue;
        }else if (colision.colide(boxArray[i]) && colideON){
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
void RigidBody::processElements(){
	colision.setPositionColide(position.x,position.y);
	sprite.setPositionChar(position.x,position.y);
}

// Adiministra o deslocamento do objeto
inline void::RigidBody::MoveAndSlide(float acelerationX,float acelerationY){
	setPosition(position.x+acelerationX,acelerationY);
}

// Instancia a imagen, a posição e a velocidade
RigidBody::RigidBody(std::string texture_path,float posX,float posY){
	sprite.setSpriteTexture(texture_path);
	setPosition(posX,posY);
	colideON=true;
}
// Instancia a imagen, a posição e a velocidade
RigidBody::RigidBody(float posX,float posY){
	setPosition(posX,posY);
	colideON=false;
}
// Instancia vazia
RigidBody::RigidBody(){
	setPosition(0,0);
	colideON=false;
}


#endif