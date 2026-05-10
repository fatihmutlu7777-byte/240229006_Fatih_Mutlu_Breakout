#ifndef TUGLA_HPP
#define TUGLA_HPP
#include <SFML/Graphics.hpp>

class Tugla{

    public:
     
    sf::RectangleShape tuglanin_sekli;
    bool kirildi_mi=false;//Tuğlalar kırıkmı değilmi kontrol ederiz.
    int dayaniklilik;
    int baslangic_cani;

    float catlak_acisi = 0.0f; // Her darbede değişecek açı.
    float catlak_yon_x = 1.0f;  // Rastgele aynalama güzel görünmesi için.
    
    static sf::Texture catlak_dokusu;

    sf::FloatRect getSinirlar() { return tuglanin_sekli.getGlobalBounds(); }


    //Yapıcı fonksyonlar

    Tugla(float x,float y,float genislik ,float yukseklik,sf::Color renk,int can);
    void ciz(sf::RenderWindow& pencere);
    void darbe_al();

    //Yıkıcı fonksyon(tuğla için)
    ~Tugla() = default;


    

};



#endif