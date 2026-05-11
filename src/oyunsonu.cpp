#include "../include/oyunsonu.hpp"

using namespace std;

Oyun_sonu::Oyun_sonu(float x, float y){
    if (!font.loadFromFile("../assets/arial.ttf")) {

        // Hata durumu için program çökmesin diye.
        
    }
    
    arka_plan_kutusu.setSize(Vector2f(500.0f,300.0f));
    arka_plan_kutusu.setFillColor(Color(255,128,0));
    arka_plan_kutusu.setOutlineThickness(3.0f);
    arka_plan_kutusu.setOutlineColor(Color::White);
    arka_plan_kutusu.setOrigin(250.0f, 150.0f);
    arka_plan_kutusu.setPosition(400.0f,300.0f);


    baslik_metni.setFont(font);
    baslik_metni.setString("Oyun Bitti");
    baslik_metni.setCharacterSize(45);
    baslik_metni.setFillColor(Color::Red);
    baslik_metni.setOrigin(baslik_metni.getLocalBounds().width / 2.0f, 0);
    baslik_metni.setPosition(400.0f,200.0f);


    skor_metni.setFont(font);
    skor_metni.setCharacterSize(35);
    skor_metni.setFillColor(Color::Blue);
    skor_metni.setPosition(400.0f, 260.0f);


    seviye_metni.setFont(font);
    seviye_metni.setCharacterSize(35);
    seviye_metni.setFillColor(Color::Blue);



    bilgi_metni.setFont(font);
    bilgi_metni.setString("Yeniden oynamak icin ENTER\nCikmak icin ESC tusuna basin.");
    bilgi_metni.setCharacterSize(22);
    bilgi_metni.setFillColor(Color::Black);
    bilgi_metni.setOrigin(bilgi_metni.getLocalBounds().width / 2.0f, 0);
    bilgi_metni.setPosition(400.0f, 360.0f);
    

}


void Oyun_sonu::skoru_ayarla(int son_skor){
    
    skor_metni.setString("Skorunuz: "+::to_string(son_skor));
    skor_metni.setOrigin(skor_metni.getLocalBounds().width / 2.0f, 0);
    skor_metni.setPosition(400.0f, 270.0f);// Ekranın tam ortası.
}

void Oyun_sonu::seviyeyi_ayarla(int son_seviye){

    seviye_metni.setString("Seviyeniz: " + ::to_string(son_seviye)); 
    seviye_metni.setOrigin(seviye_metni.getLocalBounds().width / 2.0f, 0); // Ortalarız.
    seviye_metni.setPosition(400.0f, 310.0f); // Skorun biraz altına koyuldu.
}

void Oyun_sonu::ciz(RenderWindow& pencere){
    pencere.draw(arka_plan_kutusu);
    pencere.draw(bilgi_metni);
    pencere.draw(skor_metni);
    pencere.draw(seviye_metni);
    pencere.draw(baslik_metni);

}