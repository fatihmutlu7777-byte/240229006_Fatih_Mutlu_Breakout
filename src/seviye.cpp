#include "../include/seviye.hpp"
using namespace std;


Seviye_ekrani::Seviye_ekrani(float x, float y){//Seviye özellikleri.
    seviye=1;
    
    yazi.setCharacterSize(18);
    yazi.setFillColor(sf::Color::White);
    yazi.setPosition(x,y);
    yazi.setString("Seviye: 1");
}


void Seviye_ekrani::seviye_ekle(int sonraki_seviye){//Seviye artışı.
    seviye+=sonraki_seviye;
     yazi.setString("Seviye: "+::to_string(seviye));
}



int Seviye_ekrani::getseviye(){//Seviyeyi bulmaya yarar.
    return seviye;
}



void Seviye_ekrani::seviyeyi_sifirla(){// Seviyeyi resetler.
    seviye=1;
    yazi.setString("seviye: 1");

}



void Seviye_ekrani::ciz(sf::RenderWindow& pencere){//Ekrana çizer.
    pencere.draw(yazi);
}

void Seviye_ekrani::fontu_ayarla(const sf::Font& ana_font) {//Fontu ayarlar.
    yazi.setFont(ana_font);
}