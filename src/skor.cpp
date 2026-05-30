#include "../include/skor.hpp"
#include<iostream>
using namespace std;

Skor_ekrani::Skor_ekrani(float x, float y){//Skor özellikleri.
    skor=0;
   

    
    yazi.setCharacterSize(18);
    yazi.setFillColor(sf::Color::White);
    yazi.setPosition(x,y);
    yazi.setString("Skor: 0");
}


void Skor_ekrani::skor_ekle(int puan){//Skor ekler.
    skor+=puan;
    yazi.setString("Skor: "+::to_string(skor));

}


int Skor_ekrani::getskor(){//Skoru getirir.
    return skor;
}

void Skor_ekrani::skoru_sifirla(){//Skoru resetler.
    skor=0;
    yazi.setString("Skor: 0");

}

void Skor_ekrani::ciz(sf::RenderWindow& pencere){//Ekrana çizer.
    pencere.draw(yazi);
}
void Skor_ekrani::fontu_ayarla(const sf::Font& ana_font) {//Fontu ayarlar.
    yazi.setFont(ana_font);
}