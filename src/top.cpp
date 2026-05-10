#include "../include/Top.hpp"

Top::Top(float x, float y){
    top_hizi_x = 5.0f;
    top_hizi_y = 5.0f;
    top_sekli.setRadius(5.0f);
    top_sekli.setOrigin(top_yarıcapi, top_yarıcapi); // Merkezi referans al
    top_sekli.setPosition(x, y);
    top_sekli.setFillColor(sf::Color::White);
}

void Top::guncelle() {
    top_sekli.move(top_hizi_x,top_hizi_y);

    if(top_sekli.getPosition().x<=0|| top_sekli.getPosition().x >= 800 - 20){
        top_hizi_x=-top_hizi_x;

    }
    if(top_sekli.getPosition().y<=0){
        top_hizi_y=-top_hizi_y;

    }
    
    
}

void Top::rakettensek(float raketMerkezi){
    if(top_hizi_y>0){
        top_hizi_y=-top_hizi_y; // Yukarı fırlatcak

        if (top_hizi_y > -1.0f) { 
            top_hizi_y = top_hizi_y * 1.03f; // Hızı %3 arttırdık
        }

        float TopMerkezi=top_sekli.getPosition().x + top_sekli.getRadius();


        float fark=TopMerkezi-raketMerkezi;

        top_hizi_x=fark*0.15f;
    }

}


void Top::resetle(float x, float y){
    top_sekli.setPosition(x,y);
    top_hizi_x=0.0f;
    top_hizi_y=-5.0f;
}


void Top::ciz(sf::RenderWindow& pencere) {
    pencere.draw(top_sekli);
}


