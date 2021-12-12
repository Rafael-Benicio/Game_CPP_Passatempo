# include <iostream>
# include <SFML/Graphics.hpp>
# include "class/Struct_Box.hpp"
# include "class/Struct_Position.hpp"
# include "class/Struct_Proportion.hpp"
# include "class/Camera2D.hpp"
# include "class/Node2D.hpp"
# include "class/Char.hpp"
# include "class/Colision.hpp"
# include "class/RigidBody.hpp"
# include "EntClass/Player.hpp"
# include "vars/imgs.hpp"

#define windowCol 20
#define windowRow 15
#define rect 8

// Criar Char
Player char1(imgs[0],8,0,1);
RigidBody char2(8*1,20);
RigidBody char3(8*2,20);
RigidBody char4(8*3,20);
RigidBody char5(8*4,20);
RigidBody char6(8*5,20);
RigidBody char7(8*6,20);

// Cria array de colisão
Box colisionArray[7]={
     char1.colision.point,
     char2.colision.point,
     char3.colision.point,
     char4.colision.point,
     char5.colision.point,
     char6.colision.point,
     char7.colision.point,
};

int colisionArrayLength=sizeof(colisionArray)/16;

// Camera principal
Camera2D camera(4,4,windowCol*rect,windowRow*rect);

// Functions ----------------------------------------------------

// Main functions game
// Checa os eventos primeiro
void Eventos(sf::Event *event);
// faz as atualizaçõs
void Update(sf::RenderWindow *janela);
// Desenhas os tiles
void Draw_pri2(sf::RenderWindow *janela);
// Desenha os player
void Draw_pri1(sf::RenderWindow *janela);

int main(){
     // Configura a tela
     sf::RenderWindow window(sf::VideoMode(720, 480), "Passa tempo");
     window.setFramerateLimit(60);

     char1.colision.setProportion(8,8);
     char2.colision.setProportion(8,8);
     char3.colision.setProportion(8,8);
     char4.colision.setProportion(8,8);
     char5.colision.setProportion(8,8);
     char6.colision.setProportion(8,8);
     char7.colision.setProportion(8,8);

     // Loop do jogo
     while (window.isOpen()){
          // Variavel contendo os Eventos
          sf::Event event;
          // Checa os eventos
          while (window.pollEvent(event)){
               if (event.type == sf::Event::Closed) window.close();
               Eventos(&event);    
          }
          Update(&window);
          // Draw
          Draw_pri2(&window);
          Draw_pri1(&window);
          // Apresenta o conteudo desenhado
          window.display();
     }
	return 0;
}

void Eventos(sf::Event *event){
    char1.eventButtons(event);
}

void Update(sf::RenderWindow *janela){
     // Limpa a tela
     janela->clear(sf::Color::Blue);
     // define onde a janela vai ficar
     camera.centroCamera(char1.position.x,char1.position.y);
     // Define onde a camera vai ficar
     janela->setView(camera.mainCamera());
     // Updates

     char1.processElements();
     char2.processElements();
     char3.processElements();
     char4.processElements();
     char5.processElements();
     char6.processElements();
     char7.processElements();

     colisionArray[0]=char1.colision.point;
     colisionArray[1]=char2.colision.point;
     colisionArray[2]=char3.colision.point;
     colisionArray[3]=char4.colision.point;
     colisionArray[4]=char5.colision.point;
     colisionArray[5]=char6.colision.point;
     colisionArray[6]=char7.colision.point;
     
     char1.hardColision(colisionArray,colisionArrayLength);
     char2.hardColision(colisionArray,colisionArrayLength);
     char3.hardColision(colisionArray,colisionArrayLength);
     char4.hardColision(colisionArray,colisionArrayLength);
     char5.hardColision(colisionArray,colisionArrayLength);
     char6.hardColision(colisionArray,colisionArrayLength);
     char7.hardColision(colisionArray,colisionArrayLength);

}


void Draw_pri2(sf::RenderWindow *janela){
     // janela->draw(char2.sprite.drawSP());
     // janela->draw(char3.sprite.drawSP());
     // janela->draw(char4.sprite.drawSP());
     // janela->draw(char5.sprite.drawSP());
     // janela->draw(char6.sprite.drawSP());
     // janela->draw(char7.sprite.drawSP());
};

void Draw_pri1(sf::RenderWindow *janela){
     janela->draw(char1.sprite.drawSP());

};