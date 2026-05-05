#include "Top.hpp"

Top::Top(float x, float y){
    top_hizi_x = 0.0f;
    top_hizi_y = 5.0f;
    top_sekli.setRadius(5.0f);
    top_sekli.setOrigin(top_yarıcapi, top_yarıcapi); // Merkezi referans al
    top_sekli.setPosition(x, y);
    top_sekli.setFillColor(sf::Color::White);
}

void Top::update() {
    top_sekli.move(top_hizi_x,top_hizi_y);

    
    
}

void Top::draw(sf::RenderWindow& t_window) {
    t_window.draw(top_sekli);
}

void Top::carpma() {
    if(top_sekli.getPosition().x<=0|| top_sekli.getPosition().x >= 800 - 20){
       top_hizi_x=-top_hizi_x;

    }
    if(top_sekli.getPosition().y<=0){
        top_hizi_y=-top_hizi_y;

    }
}

void Top::carpma_ust_alt() {
    top_hizi_y = -top_hizi_y;
}

sf::FloatRect Top::getBounds() const {
    return top_sekli.getGlobalBounds();
}