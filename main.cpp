# include <iostream>
# include <SFML/Graphics.hpp>
# include "class/Struct_Box.hpp"
# include "class/Struct_Position.hpp"
# include "class/Struct_Proportion.hpp"
# include "class/Camera2D.hpp"
# include "class/Char.hpp"
# include "class/RigidBody.hpp"
# include "EntClass/Player.hpp"
# include "EntClass/Tile.hpp"
# include "vars/imgs.hpp"

#define windowCol 20
#define windowRow 15
#define rect 8

// Criar Char
Player char1(imgs[0],0,0,1);
RigidBody char2(imgs[0],8,20);
RigidBody char3(imgs[0],0,20);

// Cria array de colisão
Box colisionArray[3]={
     char1.colision.point,
     char2.colision.point,
     char3.colision.point,
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

     colisionArray[0]=char1.colision.point;
     colisionArray[1]=char2.colision.point;
     colisionArray[2]=char3.colision.point;
     
     char1.hardColision(colisionArray,colisionArrayLength);

}


void Draw_pri2(sf::RenderWindow *janela){
     
};

void Draw_pri1(sf::RenderWindow *janela){
     janela->draw(char1.drawSP());
     janela->draw(char2.drawSP());
     janela->draw(char3.drawSP());

};