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
    int skor;
    bool oyun_bitti_mi;

    sf::Font font;
    sf::Text skor_metni;          // Büyük skor.
    sf::Text anlik_skor_metni;     // Kalplerin altındaki küçük skor.
    sf::Text bitis_metni;         // "OYUN BİTTİ" yazısı.
    sf::Text yeniden_baslat_metni; // "E/H" seçim yazısı.
    sf::Texture kalp_logosu;
    


    // Özel yardımcı fonksiyonlar. 

    void olaylari_isle();
    void guncelle();
    void ciz();
    void konumları_sıfırla();
    void oyunu_sıfırla();
public:
    // Yapıcı ve Yıkıcı Fonksiyonlar.
    Oyun();
    ~Oyun() = default;

    // Oyunu başlatan ana döngü.
    void calistir();
};

#endif