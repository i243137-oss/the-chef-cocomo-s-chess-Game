#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main(){
    sf::RenderWindow window(sf::VideoMode(800,800),"Chef Cocomo's Chess Game");
    sf::RectangleShape screen1;
    sf::RectangleShape b1,b2,b3;
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
      


   
    Vector2i c;
   
    sf::Texture t1;
    sf::Texture t2;
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
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }
         c=Mouse::getPosition(window);
         if(b1.getGlobalBounds().contains(c.x,c.y)){
            text1.setFillColor(sf::Color(60, 40, 20));
         }else{
            text1.setFillColor(Color::White);
         }
          if(b2.getGlobalBounds().contains(c.x,c.y)){
            text2.setFillColor(sf::Color(60, 40, 20));
         }else{
            text2.setFillColor(Color::White);
         }
          if(b3.getGlobalBounds().contains(c.x,c.y)){
            text3.setFillColor(sf::Color(60, 40, 20));
         }else{
            text3.setFillColor(Color::White);
         }
    cout<<c.x<<"  "<<c.y<<endl;

        window.clear();
        window.draw(screen1);
        window.draw(b1);
        window.draw(b2);
        window.draw(b3);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
    

}