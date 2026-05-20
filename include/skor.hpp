#ifndef SKOR_HPP
#define SKOR_HPP
#include <SFML/Graphics.hpp>


class Skor_ekrani{

    private:
    int skor;
    
    sf::Text yazi;

    public:

    Skor_ekrani(float x ,float y);
    void skor_ekle(int puan);
    int getskor();
    void skoru_sifirla();
    void ciz(sf::RenderWindow& pencere);
    void fontu_ayarla(const sf::Font& ana_font);


};


#endif
