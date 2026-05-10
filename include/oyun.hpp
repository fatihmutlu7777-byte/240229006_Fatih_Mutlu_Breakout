#ifndef OYUN_HPP
#define OYUN_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/top.hpp"
#include "../include/raket.hpp"
#include "../include/tugla.hpp"



class Oyun {
private:
    // SFML Penceresi
    sf::RenderWindow pencere;

    // Oyunun Nesneleri 
    Top topum;
    Raket raketim;
    std::vector <Tugla> tuglalarim;
    int can;


    // Özel yardımcı fonksiyonlar 

    void olaylari_isle();
    void guncelle();
    void ciz();
    void konumları_sıfırla();
public:
    // Yapıcı ve Yıkıcı Fonksiyonlar
    Oyun();
    ~Oyun() = default;

    // Oyunu başlatan ana döngü
    void calistir();
};

#endif