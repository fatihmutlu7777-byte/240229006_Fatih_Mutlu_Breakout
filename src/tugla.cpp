#include"../include/tugla.hpp"
#include"../include/top.hpp"

sf::Texture Tugla::catlak_dokusu;


Tugla::Tugla(float x,float y,float genişlik,float yukseklik,sf::Color renk,int tugla_cani){
    dayaniklilik = tugla_cani;       
    baslangic_cani = tugla_cani;
    tuglanin_sekli.setPosition(x,y);
    tuglanin_sekli.setSize(sf::Vector2f(genişlik,yukseklik));
    tuglanin_sekli.setFillColor(sf::Color::Yellow);
    tuglanin_sekli.setOutlineThickness(5);
    tuglanin_sekli.setOutlineColor(sf::Color(00,02,18));
    tuglanin_sekli.setFillColor(renk);

}

void Tugla::ciz(sf::RenderWindow& pencere){
    if(!kirildi_mi){
        pencere.draw(tuglanin_sekli);

        if (dayaniklilik < baslangic_cani) {
            sf::Sprite catlakSprite;
            catlakSprite.setTexture(catlak_dokusu);

            sf::Vector2u size = catlak_dokusu.getSize();
            catlakSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);

            // Konumu tuğlanın tam ortasına getir.
            catlakSprite.setPosition(
                tuglanin_sekli.getPosition().x + tuglanin_sekli.getSize().x / 2.0f,
                tuglanin_sekli.getPosition().y + tuglanin_sekli.getSize().y / 2.0f
            );
            // ÖLÇEKLENDİRME VE RASTGELELİK
            float sX = (tuglanin_sekli.getSize().x / size.x) * catlak_yon_x;
            float sY = tuglanin_sekli.getSize().y / size.y;
            catlakSprite.setScale(sX, sY);
            catlakSprite.setRotation(catlak_acisi);
            pencere.draw(catlakSprite);
        }
    }
}


void Top::tugladansek(){
      top_hizi_y = -top_hizi_y;

}

void Tugla::darbe_al(){
    dayaniklilik--;


    catlak_acisi = static_cast<float>(rand() % 360); // 0-359 arası rastgele açı.
    catlak_yon_x = (rand() % 2 == 0) ? 1.0f : -1.0f; // Rastgele sağ-sol aynalama işlemi.


    if(dayaniklilik<=0){
        kirildi_mi=true;
    }
    
}