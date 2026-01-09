#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main(){
    sf::RenderWindow window(sf::VideoMode(800,800),"Chef Cocomo's Chess Game");
    sf::RectangleShape screen1;
    sf::RectangleShape b1,b2,b3;
    sf::RectangleShape bord;
    bord.setSize(Vector2f(800,600));
    
    b1.setSize(Vector2f(220,110));
    b2.setSize(Vector2f(220,110));
    b3.setSize(Vector2f(220,110));
    sf:: Font fd;
    fd.loadFromFile("fd.ttf");
    sf::Text text1,text2,text3;
    text1.setFont(fd);
     text2.setFont(fd);
      text3.setFont(fd);
      text1.setCharacterSize(28);
      text1.setString("New Game ");
      text1.setPosition(Vector2f(95,680));
      text1.setStyle(sf::Text::Bold);
    
      text2.setCharacterSize(28);
      text2.setString("Options");
      text2.setPosition(Vector2f(345,680));
      text2.setStyle(Text::Bold);

      text3.setCharacterSize(28);
      text3.setString("Exit");
      text3.setPosition(Vector2f(595,680));
      text3.setStyle(Text::Bold);
      
      sf::RectangleShape brd[8][8];
      for(int i=0;i<7; i++){
         for(int j=0; j<8; j++){
            brd[i][j].setSize(Vector2f(75,100));
            brd[i][j].setFillColor(Color::Transparent);
          
            brd[i][j].setPosition(Vector2f(75*i,100*j));

         }
      }

      


   
    Vector2i c;
   
    sf::Texture t1;
    sf::Texture t2;
    sf::Texture board;
    board.loadFromFile("assests/board.png");
    bord.setTexture(&board);
    t2.loadFromFile("button.png");

    t1.loadFromFile("screen1.png");
     

    screen1.setSize(Vector2f(800,800));
    screen1.setTexture(&t1);
    b1.setTexture(&t2);
    b2.setTexture(&t2);
    b3.setTexture(&t2);

    

     b1.setPosition(Vector2f(50,640));
     b2.setPosition(Vector2f(300,640));
     b3.setPosition(Vector2f(550,640));
     int i=0;
     int currscr=0;
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
            if(currscr==1){

            }
            
            if(currscr==0){
            if(event.type==Event::KeyPressed){

               if(event.key.code==Keyboard::Left){
                 
                  i--;
                  if(i<1) i=1;

               }
                if(event.key.code==Keyboard::Right){
                 
                  i++;
                  if(i>3) i=1;

               }
               
               if(event.key.code==Keyboard::Enter && i==1){
                  currscr=1;
               }
            
            }
            if(event.type==Event::MouseButtonPressed){
               if(event.mouseButton.button==Mouse::Right){
                  currscr=1;
               }
            }
         }
        }
        
         c=Mouse::getPosition(window);
         if(currscr==0){
              if(b1.getGlobalBounds().contains(c.x,c.y)){
               i=1;
              }
              if(b2.getGlobalBounds().contains(c.x,c.y)){
               i=2;
              }
              if(b3.getGlobalBounds().contains(c.x,c.y)){
               i=3;
              }
         text3.setFillColor(Color::White);
         text2.setFillColor(Color::White);
         text1.setFillColor(Color::White);
         if(i==1){
            text1.setFillColor(sf::Color(60, 40, 20));
         }
          else if(i==2){
            text2.setFillColor(sf::Color(60, 40, 20));
         }
        else  if(i==3){
            text3.setFillColor(sf::Color(60, 40, 20));
         }
    

        window.clear();
        window.draw(screen1);
        window.draw(b1);
        window.draw(b2);
        window.draw(b3);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();
      }else if(currscr==1){
          c=Mouse::getPosition(window);
          int x=c.x/100;
          int y=c.y/100;
        
         window.clear();
         window.draw(screen1);
         window.draw(bord);
         for(int i=0; i<8; i++){
            for(int j=0;j<8; j++){
               window.draw(brd[i][j]);
            }
         }
         window.display();
      }
      
    }

    

}
