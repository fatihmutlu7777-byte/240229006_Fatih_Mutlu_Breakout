#include "../include/seviye.hpp"
using namespace std;


Seviye_ekrani::Seviye_ekrani(float x, float y){
    seviye=1;
    
    yazi.setCharacterSize(18);
    yazi.setFillColor(sf::Color::White);
    yazi.setPosition(x,y);
    yazi.setString("Seviye: 1");
}


void Seviye_ekrani::seviye_ekle(int sonraki_seviye){
    seviye+=sonraki_seviye;
     yazi.setString("Seviye: "+::to_string(seviye));
}



int Seviye_ekrani::getseviye(){
    return seviye;
}



void Seviye_ekrani::seviyeyi_sifirla(){
    seviye=1;
    yazi.setString("seviye: 1");

}



void Seviye_ekrani::ciz(sf::RenderWindow& pencere){
    pencere.draw(yazi);
}

void Seviye_ekrani::fontu_ayarla(const sf::Font& ana_font) {
    yazi.setFont(ana_font);
}