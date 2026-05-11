#ifndef SKOR_HPP
#define SKOR_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Skor_ekrani{

    private:
    int skor;
    Font font;
    Text yazi;

    public:

    Skor_ekrani(float x ,float y);
    void skor_ekle(int puan);
    int getskor();
    void skoru_sifirla();
    void ciz(RenderWindow& pencere);


};


#endif
