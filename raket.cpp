#include"raket.hpp"
using namespace sf;

Raket::Raket(){
   raketin_hizi=15.0f;
   raketin_sekli.setSize(Vector2f(100.0f,20.0f));
   raketin_sekli.setFillColor(Color::White);
   raketin_sekli.setPosition(350.0f,550.0f);




}

void Raket::guncelle(){
    if(Keyboard::isKeyPressed(Keyboard::Left)&& raketin_sekli.getPosition().x>0){
        
        raketin_sekli.move(-raketin_hizi,0.0f);

    }
    
    
    if(Keyboard::isKeyPressed(Keyboard::Right)&& raketin_sekli.getPosition().x < 800 - 100){
        
        raketin_sekli.move(raketin_hizi,0.0f);


    }

}


void Raket::ciz(RenderWindow& pencere){

    pencere.draw(raketin_sekli);
}

sf::FloatRect Raket::getBounds() const {
    return raketin_sekli.getGlobalBounds();
}