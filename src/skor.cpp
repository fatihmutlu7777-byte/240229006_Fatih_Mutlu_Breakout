#include "../include/skor.hpp"
#include<iostream>
using namespace std;

Skor_ekrani::Skor_ekrani(float x, float y){
    skor=0;
   

    
    yazi.setCharacterSize(18);
    yazi.setFillColor(sf::Color::White);
    yazi.setPosition(x,y);
    yazi.setString("Skor: 0");
}


void Skor_ekrani::skor_ekle(int puan){
    skor+=puan;
    yazi.setString("Skor: "+::to_string(skor));

}


int Skor_ekrani::getskor(){
    return skor;
}

void Skor_ekrani::skoru_sifirla(){
    skor=0;
    yazi.setString("Skor: 0");

}

void Skor_ekrani::ciz(sf::RenderWindow& pencere){
    pencere.draw(yazi);
}
void Skor_ekrani::fontu_ayarla(const sf::Font& ana_font) {
    yazi.setFont(ana_font);
}