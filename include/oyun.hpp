#ifndef OYUN_HPP
#define OYUN_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/top.hpp"
#include "../include/raket.hpp"
#include "../include/tugla.hpp"
#include "../include/oyunsonu.hpp"
#include "../include/skor.hpp"





class Oyun {
private:
    // SFML Penceresi
    sf::RenderWindow pencere;

    // Oyunun Nesneleri 
    Top topum;
    Raket raketim;
    Oyun_sonu oyunsonu_ekranim;
    Skor_ekrani skor_ekranim;
    std::vector <Tugla> tuglalarim;
    sf::Texture kalp_logosu;
    sf::Font font;
    int can;
    int skor;
    bool oyun_bitti_mi;
    int mevcut_seviye;
    
    


    // Özel yardımcı fonksiyonlar. 

    void olaylari_isle();
    void guncelle();
    void ciz();
    void konumları_sıfırla();
    void oyunu_sıfırla();
    void tuglalari_diz();
    void yeni_seviye_yukle();
    
public:
    // Yapıcı ve Yıkıcı Fonksiyonlar.
    Oyun();
    ~Oyun() = default;

    // Oyunu başlatan ana döngü.
    void calistir();
};

#endif