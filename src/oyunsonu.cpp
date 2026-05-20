#include "../include/oyunsonu.hpp"

using namespace std;

Oyun_sonu::Oyun_sonu(float x, float y){
   
    
    arka_plan_kutusu.setSize(sf::Vector2f(500.0f,300.0f));
    arka_plan_kutusu.setFillColor(sf::Color(255,128,0));
    arka_plan_kutusu.setOutlineThickness(3.0f);
    arka_plan_kutusu.setOutlineColor(sf::Color::White);
    arka_plan_kutusu.setOrigin(250.0f, 150.0f);
    arka_plan_kutusu.setPosition(400.0f,300.0f);


    
    baslik_metni.setString("Oyun Bitti");
    baslik_metni.setCharacterSize(45);
    baslik_metni.setFillColor(sf::Color::Red);
    baslik_metni.setOrigin(baslik_metni.getLocalBounds().width / 2.0f, 0);
    baslik_metni.setPosition(300.0f,150.0f);


    
    skor_metni.setCharacterSize(35);
    skor_metni.setFillColor(sf::Color::Blue);
   


    
    seviye_metni.setCharacterSize(35);
    seviye_metni.setFillColor(sf::Color::Blue);



    
    bilgi_metni.setString("Yeniden oynamak icin ENTER\nCikmak icin ESC tusuna basin.");
    bilgi_metni.setCharacterSize(22);
    bilgi_metni.setFillColor(sf::Color::Black);
    bilgi_metni.setOrigin(bilgi_metni.getLocalBounds().width / 2.0f, 0);
    bilgi_metni.setPosition(250.0f, 360.0f);
    

}


void Oyun_sonu::skoru_ayarla(int son_skor){
    
    skor_metni.setString("Skorunuz: "+::to_string(son_skor));
    skor_metni.setOrigin(skor_metni.getLocalBounds().width / 2.0f, 0);
    skor_metni.setPosition(400.0f, 250.0f);// Ekranın tam ortası.
}

void Oyun_sonu::seviyeyi_ayarla(int son_seviye){

    seviye_metni.setString("Seviyeniz: " + ::to_string(son_seviye)); 
    seviye_metni.setOrigin(seviye_metni.getLocalBounds().width / 2.0f, 0); // Ortalarız.
    seviye_metni.setPosition(400.0f, 300.0f); // Skorun biraz altına koyuldu.
}



void Oyun_sonu::ciz(sf::RenderWindow& pencere){
    pencere.draw(arka_plan_kutusu);
    pencere.draw(bilgi_metni);
    pencere.draw(skor_metni);
    pencere.draw(seviye_metni);
    pencere.draw(baslik_metni);


}

void Oyun_sonu::fontu_ayarla(const sf::Font& ana_font) {
    baslik_metni.setFont(ana_font);
    skor_metni.setFont(ana_font);
    bilgi_metni.setFont(ana_font);
    seviye_metni.setFont(ana_font);
}