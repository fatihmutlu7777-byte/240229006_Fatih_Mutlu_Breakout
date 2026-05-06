#ifndef TUGLA_HPP
#define TUGLA_HPP
#include <SFML/Graphics.hpp>

class Tugla{

    public:
     
    sf::RectangleShape tuglanin_sekli;
    bool kirildi_mi=false;//Tuğlalar kırıkmı değilmi kontrol ederiz

    sf::FloatRect getSinirlar() { return tuglanin_sekli.getGlobalBounds(); }


    //Yapıcı fonksyonlar

    Tugla(float x,float y,float genislik ,float yukseklik,sf::Color renk);
    void ciz(sf::RenderWindow& pencere);

    //Yıkıcı fonksyon(tuğla için)
    ~Tugla() = default;


    

};



#endif