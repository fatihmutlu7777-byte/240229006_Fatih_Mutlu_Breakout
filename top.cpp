#include "Top.hpp"

Top::Top(float x, float y, float x_hizi, float y_hizi, float yaricap) 
    : top_yarıcapi(yaricap) 
{
    top_hizi.x = x_hizi;
    top_hizi.y = y_hizi;

    top_sekli.setRadius(top_yarıcapi);
    top_sekli.setOrigin(top_yarıcapi, top_yarıcapi); // Merkezi referans al
    top_sekli.setPosition(x, y);
    top_sekli.setFillColor(sf::Color::White);
}

void Top::update() {
    top_sekli.move(top_hizi);
}

void Top::draw(sf::RenderWindow& t_window) {
    t_window.draw(top_sekli);
}

void Top::carpma() {
    top_hizi.x = -top_hizi.x;
}

void Top::carpma_ust_alt() {
    top_hizi.y = -top_hizi.y;
}

sf::FloatRect Top::getBounds() const {
    return top_sekli.getGlobalBounds();
}