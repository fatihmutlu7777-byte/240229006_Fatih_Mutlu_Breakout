#ifndef SEVİYE_HPP
#define SEVİYE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;


class Seviye_ekrani{

    private:
    Font font;
    Text yazi;
    int seviye;


    public:
    Seviye_ekrani(float x ,float y);
    void skor_ekle(int sonraki_seviye);
    void seviyeyi_sifirla();
    int getseviye();
    void ciz(RenderWindow& pencere);


};





#endif