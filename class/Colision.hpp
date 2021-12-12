#ifndef COLISION_HPP_INCLUDED
#define COLISION_HPP_INCLUDED



class Colision2D:public Node2D{
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
		// Aumenta e diminue o tamanho da caixa de colisão
		void setMargins(float x,float y,float w,float h){
			margin.topY=x;
			margin.topX=y;
			margin.bottomX=w;
			margin.bottomY=h;
		}

		// Configura as posições
		void setPositionColide(float Ox,float Oy,float Ow,float Oh){
				point.topX=position.x+margin.topX+Ox;
				point.topY=position.y+margin.topY+Oy;
				point.bottomX=position.x+margin.bottomX+Ow+Ox;
				point.bottomY=position.y+margin.bottomY+Oh+Oy;
		};
};





#endif // CHAR_HPP_INCLUDED