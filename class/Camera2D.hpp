#ifndef CAMERA2D_HPP_INCLUDED
#define CAMERA2D_HPP_INCLUDED

class Camera2D:public Node2D{
	public:
		// cria view
		sf::View view;
		// Proporção 
		Proportion proportion;
		// Function ----------------------------------------
		// retorna a VewPort
		inline sf::View mainCamera(){ return view; }
		// Configura o centro da camera
		void setCentroCamera(float x,float y){
		    view.setCenter((x+position.x),(y+position.y));
		}
		// Constructor -------------------------------------
		Camera2D(float pos_x, float pos_y, float width, float height){
			setPosition(pos_x,pos_y);
			proportion.width=width;
			proportion.height=height;
			// Configura o tamanho da view
			view.reset(sf::FloatRect(position.x,position.y,proportion.width,proportion.height));
		};

	private:
};

#endif