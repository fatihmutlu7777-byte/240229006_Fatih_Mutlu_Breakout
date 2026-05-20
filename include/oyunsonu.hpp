#ifndef OYUNSONU_HPP
#define OYUNSONU_HPP
#include <string>
#include <SFML/Graphics.hpp>



class Oyun_sonu{

    private:
    sf::RectangleShape arka_plan_kutusu;
    sf::Text baslik_metni;
    sf::Text skor_metni;
    sf::Text bilgi_metni;
    sf::Text seviye_metni;

    public:

    Oyun_sonu(float x,float y);
    void skoru_ayarla(int son_skor);
    void seviyeyi_ayarla(int son_seviye);
    void ciz(sf::RenderWindow& pencere);
    void fontu_ayarla(const sf::Font& ana_font);
    

};

#endif 

