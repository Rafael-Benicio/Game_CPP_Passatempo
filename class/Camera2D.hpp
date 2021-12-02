#ifndef CAMERA2D_HPP_INCLUDED
#define CAMERA2D_HPP_INCLUDED

class Camera2D{
	public:
		// cria view
		sf::View view;
		// posição da camera
		Position position;
		// Proporção 
		Proportion proportion;
		// Function ----------------------------------------
		void centroCamera(float x,float y);
		sf::View mainCamera();
		// Constructor -------------------------------------
		Camera2D(float pos_x, float pos_y, float width, float height);
	private:
};

void Camera2D::centroCamera(float x,float y){
    view.setCenter((x+position.x),(y+position.y));
}

inline sf::View Camera2D::mainCamera(){ return view; }

Camera2D::Camera2D(float pos_x, float pos_y, float width, float height){
	position.x=pos_x;
	position.y=pos_y;
	proportion.width=width;
	proportion.height=height;

	view.reset(sf::FloatRect(position.x,position.y,proportion.width,proportion.height));
};

#endif