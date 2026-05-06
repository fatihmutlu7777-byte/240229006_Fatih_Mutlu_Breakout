#include "Top.hpp"

Top::Top(float x, float y){
    top_hizi_x = 5.0f;
    top_hizi_y = 5.0f;
    top_sekli.setRadius(5.0f);
    top_sekli.setOrigin(top_yarıcapi, top_yarıcapi); // Merkezi referans al
    top_sekli.setPosition(x, y);
    top_sekli.setFillColor(sf::Color::White);
}

void Top::update() {
    top_sekli.move(top_hizi_x,top_hizi_y);

    
    
}

void Top::ciz(sf::RenderWindow& pencere) {
    pencere.draw(top_sekli);
}


sf::FloatRect Top::getBounds() const {
    return top_sekli.getGlobalBounds();
}