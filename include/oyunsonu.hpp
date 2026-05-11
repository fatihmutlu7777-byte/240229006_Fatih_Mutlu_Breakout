#ifndef OYUNSONU_HPP
#define OYUNSONU_HPP
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class Oyun_sonu{

    private:
    Font font;
    RectangleShape arka_plan_kutusu;
    Text baslik_metni;
    Text skor_metni;
    Text bilgi_metni;
    Text seviye_metni;

    public:

    Oyun_sonu(float x,float y);
    void skoru_ayarla(int son_skor);
    void seviyeyi_ayarla(int son_seviye);
    void ciz(RenderWindow& pencere);
    

};

#endif 

