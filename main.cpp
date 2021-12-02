# include <iostream>
# include <map>
# include <SFML/Graphics.hpp>
# include "class/Struct_Box.hpp"
# include "class/Struct_Position.hpp"
# include "class/Struct_Proportion.hpp"
# include "class/Camera2D.hpp"
# include "class/Char.hpp"
# include "EntClass/Player.hpp"
# include "EntClass/Tile.hpp"
# include "vars/imgs.hpp"

#define windowCol 20
#define windowRow 15
#define rect 8


// Criar Char
Player char1(imgs[0],20,0,2);
Player char2(imgs[0],0,0,5);

// Criar Tile


// Camera principal
Camera2D camera(4,4,windowCol*rect,windowRow*rect);

// Functions ----------------------------------------------------

// Main functions game
void Update(sf::RenderWindow *janela);
void Eventos(sf::Event *event);
void Draw(sf::RenderWindow *janela);
void DrawTile(sf::RenderWindow *janela);

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
          DrawTile(&window);
          Draw(&window);
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
     char1.updateElements();
     char2.updateElements();

     if (char1.colision.colide(char2.colision.point)){
          char1.vector_move.x*=-1;
          char1.vector_move.y*=-1;
     }
}

void DrawTile(sf::RenderWindow *janela){
     
};

void Draw(sf::RenderWindow *janela){
     janela->draw(char1.drawSP());
     janela->draw(char2.drawSP());

};