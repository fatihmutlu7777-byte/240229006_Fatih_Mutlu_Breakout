#ifndef SEVİYE_HPP
#define SEVİYE_HPP
#include <SFML/Graphics.hpp>



class Seviye_ekrani{

    private:
    sf::Text yazi;
    int seviye;


    public:
    Seviye_ekrani(float x ,float y);
    void seviye_ekle(int sonraki_seviye);
    void seviyeyi_sifirla();
    int getseviye();
    void ciz(sf::RenderWindow& pencere);
    void fontu_ayarla(const sf::Font& ana_font);


};





#endif