#include"../include/tugla.hpp"
#include"../include/top.hpp"


Tugla::Tugla(float x,float y,float genişlik,float yukseklik,sf::Color renk){
    tuglanin_sekli.setPosition(x,y);
    tuglanin_sekli.setSize(sf::Vector2f(genişlik,yukseklik));
    tuglanin_sekli.setFillColor(sf::Color::Yellow);
    tuglanin_sekli.setOutlineThickness(5);
    tuglanin_sekli.setOutlineColor(sf::Color(00,02,18));
    tuglanin_sekli.setFillColor(renk);

}

void Tugla::ciz(sf::RenderWindow& pencere){
    if(!kirildi_mi){
        pencere.draw(tuglanin_sekli);
    }
}



void Top::tugladansek(){
      top_hizi_y = -top_hizi_y;

}