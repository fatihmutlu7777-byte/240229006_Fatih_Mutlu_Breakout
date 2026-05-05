#ifndef OYUN_HPP
#define OYUN_HPP
#include <SFML/Graphics.hpp>
#include "top.hpp"
#include "raket.hpp" 

class Oyun {
private:
    // SFML Penceresi
    sf::RenderWindow pencere;

    // Oyunun Nesneleri 
    Top topum;
    Raket raketim;

    // Özel yardımcı fonksiyonlar 
    void olaylari_isle();
    void guncelle();
    void ciz();

public:
    // Yapıcı ve Yıkıcı Fonksiyonlar
    Oyun();
    ~Oyun() = default;

    // Oyunu başlatan ana döngü
    void calistir();
};

#endif