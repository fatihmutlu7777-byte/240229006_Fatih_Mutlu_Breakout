#include "../include/skor.hpp"
#include<iostream>
using namespace std;

Skor_ekrani::Skor_ekrani(float x, float y){
    skor=0;
    if (!font.loadFromFile("../assets/arial.ttf")) {

        // Hata durumu için program çökmesin diye.
        
    }

    yazi.setFont(font);
    yazi.setCharacterSize(24);
    yazi.setFillColor(Color::White);
    yazi.setPosition(x,y);
    yazi.setString("skor: 0");
}


void Skor_ekrani::skor_ekle(int puan){
    skor+=puan;
    yazi.setString("skor: "+::to_string(skor));

}


int Skor_ekrani::getskor(){
    return skor;
}

void Skor_ekrani::skoru_sifirla(){
    skor=0;
    yazi.setString("skor: 0");

}

void Skor_ekrani::ciz(RenderWindow& pencere){
    pencere.draw(yazi);
}