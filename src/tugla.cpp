#include"../include/tugla.hpp"
#include"../include/top.hpp"

sf::Texture Tugla::catlak_dokusu;


Tugla::Tugla(float x,float y,float genişlik,float yukseklik,sf::Color renk,int tugla_cani){//Tuğlaların özellikleri.
    dayaniklilik = tugla_cani;       
    baslangic_cani = tugla_cani;
    tuglanin_sekli.setPosition(x,y);
    tuglanin_sekli.setSize(sf::Vector2f(genişlik,yukseklik));
    tuglanin_sekli.setFillColor(sf::Color::Yellow);
    tuglanin_sekli.setOutlineThickness(5);
    tuglanin_sekli.setOutlineColor(sf::Color(00,02,18));
    tuglanin_sekli.setFillColor(renk);

}




void Tugla::ciz(sf::RenderWindow& pencere){//Ekrana çizer.
    if(!kirildi_mi){
        pencere.draw(tuglanin_sekli);

        //Eğer tuğla hasar aldıysa çatlakları çizer.
        if (dayaniklilik < baslangic_cani) {
            
            // Tuğlanın kaç kere vurulduğunu hesaplıyoruz.
            int alinan_hasar = baslangic_cani - dayaniklilik;

            sf::Sprite catlakSprite;
            catlakSprite.setTexture(catlak_dokusu);

            sf::Vector2u size = catlak_dokusu.getSize();
            catlakSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);

            // Çatlağı tuğlanın tam merkezine oturtur.
            catlakSprite.setPosition(
                tuglanin_sekli.getPosition().x + tuglanin_sekli.getSize().x / 2.0f,
                tuglanin_sekli.getPosition().y + tuglanin_sekli.getSize().y / 2.0f
            );

            // Matematiksel Hesaplamalarımız.
            float brick_w = tuglanin_sekli.getSize().x;
            float brick_h = tuglanin_sekli.getSize().y;
            float tex_w = size.x;
            float tex_h = size.y;

           
            // KATMAN KATMAN HASAR EFEKTLERİ (ÜST ÜSTE BİNER)
           

            // 1. VURUŞ: DİKEY ÇATLAK
            if (alinan_hasar >= 1) {
                catlakSprite.setRotation(0); 
                // Normal ölçekleme: Tuğlanın boyuna ve enine tam uydururuz.
                catlakSprite.setScale(brick_w / tex_w, brick_h / tex_h);
                pencere.draw(catlakSprite);
            }

            // 2. VURUŞ: YATAY ÇATLAK (Dikeyin Üstüne Eklenir)
            if (alinan_hasar >= 2) {
                catlakSprite.setRotation(90); 
                //Resim 90 derece döndüğü için X ve Y ölçeklerini ters çeviririz.
                // Böylece resim yan yattığında bile tuğlanın o daracık yüksekliğinden dışarı taşmaz.
                catlakSprite.setScale(brick_h / tex_w, brick_w / tex_h);
                pencere.draw(catlakSprite);
            }

            // 3. VURUŞ: TERS ÇATLAK (Her ikisinin de üstüne eklenip paramparça yapar)
            if (alinan_hasar >= 3) {
                catlakSprite.setRotation(180); 
                // Sadece X eksenine eksi (-) vererek aynalama yapıyoruz görüntü iyice karışıp gerçekçi oluyor.
                catlakSprite.setScale(-brick_w / tex_w, brick_h / tex_h);
                pencere.draw(catlakSprite);
            }
        }
    }
}




void Tugla::darbe_al(){//Tuğlaya çarptımı bakar ve tuğlanın canını azaltır.
    dayaniklilik--;


    catlak_acisi = static_cast<float>(rand() % 360); // 0-359 arası rastgele açı.
    catlak_yon_x = (rand() % 2 == 0) ? 1.0f : -1.0f; // Rastgele sağ-sol aynalama işlemi.


    if(dayaniklilik<=0){
        kirildi_mi=true;
    }
    
}