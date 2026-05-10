#include "../include/oyun.hpp"
#include <ctime>
using namespace sf;




// Yapıcı Fonksiyon: Pencereyi açar ve başlangıç ayarlarını yapar başlangıçta direk verdiğimiz değerlerde oluşsun diye ':' şeklinde yaparız '{}' yapmak yerine performansı arttırır.
Oyun::Oyun() 
    : pencere(VideoMode(800.0f, 600.0f), "Breakout - Fatih Mutlu"),topum(400.0f, 450.0f),can(3),skor(0),oyun_bitti_mi(false)// Topu ekranın ortasına koymuş olduk.
{
    pencere.setFramerateLimit(60); // Oyunun çok hızlı akmaması için 60 FPS'e sabitledik.
    srand(static_cast<unsigned>(time(0)));//Bize kırık şekillerinde random değerler vermesi için.


    
    if (!kalp_logosu.loadFromFile("../assets/kalp.png")) {
        // Hata durumu için program çökmesin diye.
    }
    if (!Tugla::catlak_dokusu.loadFromFile("../assets/catlak.png")) {
        
        // Hata durumu için program çökmesin diye.

    }
    if (!font.loadFromFile("../assets/arial.ttf")) {

        // Hata durumu için program çökmesin diye.
        
    }


    bitis_metni.setFont(font);
    bitis_metni.setCharacterSize(40);
    bitis_metni.setFillColor(sf::Color::Red);   
    bitis_metni.setPosition(200, 250);

    yeniden_baslat_metni.setFont(font);
    yeniden_baslat_metni.setCharacterSize(20);
    yeniden_baslat_metni.setPosition(150, 350);

   anlik_skor_metni.setFont(font);
   anlik_skor_metni.setCharacterSize(18);
   anlik_skor_metni.setPosition(10, 50);

    // 8 farklı küme için 2x4'lük bir renk matrisi oluşturuyoruz.
sf::Color kumeRenkleri[2][4] = {
    {sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan},
    {sf::Color(163,66,86), sf::Color(255, 165, 0), sf::Color(0,153,76), sf::Color(255, 0, 0)},
    
};

// Toplam 8 satır ve 20 sütunluk döngü.
for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 20; j++) { 
            float xPozisyonu = (j * 25.0f) + 92.5f; 
            float yPozisyonu = (i * 25.0f) + 50.0f; 

            if (j >= 5) xPozisyonu += 40.0f; 
            if (j >= 10) xPozisyonu += 40.0f; 
            if (j >= 15) xPozisyonu += 40.0f; 
            if (i >= 4) yPozisyonu += 40.0f; 

            int kumeSatiri = i / 4; 
            int kumeSutunu = j / 5; 
            sf::Color gecerliRenk = kumeRenkleri[kumeSatiri][kumeSutunu];

           
            int satir_ıd_x = i % 4; //Satırları bulduk.
            int tugla_cani;
            if (satir_ıd_x == 3){
                tugla_cani = 1; // En alt: 1 vuruş.
            }
            else if (satir_ıd_x == 2){
                tugla_cani = 2; // Orta alt: 2 vuruş.
            }
        
            else if (satir_ıd_x== 1){
                tugla_cani = 3; // Orta üst: 3 vuruş.
            }
            else{
                tugla_cani = 4; // En üst: 4 vuruş
            }

            tuglalarim.push_back(Tugla(xPozisyonu, yPozisyonu, 20.0f, 20.0f, gecerliRenk, tugla_cani));
        }
    }
}



void Oyun::calistir() {
    // Oyunun ana döngüsü.
    while (pencere.isOpen()) {
        olaylari_isle();
        guncelle();
        ciz();
    }
}

void Oyun::olaylari_isle(){
    sf::Event olay;
    while (pencere.pollEvent(olay)) {
        if (olay.type == sf::Event::Closed) pencere.close();

        // Kullanıcıdan isteyecek.
        if (oyun_bitti_mi && olay.type == sf::Event::KeyPressed) {
            if (olay.key.code == sf::Keyboard::E) {
                oyunu_sıfırla(); 
            } else if (olay.key.code == sf::Keyboard::H) {
                pencere.close();
            }
        }
    }
}

void Oyun::guncelle() {
   

    if (oyun_bitti_mi) return;


    raketim.guncelle();
    topum.guncelle();


     for (auto& t : tuglalarim) {
        if (!t.kirildi_mi && topum.getSinirlar().intersects(t.getSinirlar())) {
            t.darbe_al();
            if (t.kirildi_mi) {
                skor += 10;
            }
            topum.tugladansek();
            break; 
        }
    }
        
    if(topum.getSinirlar().intersects(raketim.getSinirlar())){ //Topun sınırı raketin sınırıyla kesiştimi demek.
       
        float RaketMerkezi=raketim.getSinirlar().left +(raketim.getSinirlar().width / 2.0f); // 2 ye bölüyoz çünü merkezini eklicez x in başlangıcına böylece tam orta nokta bulcaz neden .left yaptık çünkü SFML de right yok left top width height var right yapıncada açılıyo çalışıyor ama hata veriyor neden burda yaptık burası yönetici topu değiştircez top.c++ da yapsam include lar ve fazla fonksyonlar gerekicekti bizde yöneticide yaptık ara işlemi ve değeri top.c++ a aktardık.
        
        topum.rakettensek(RaketMerkezi);// Merkeze göre nasıl sektiği merkez koordinatını veririz buna göre ne kadar sapma varsa -hız_x ona göre belirlenir sekmede.
    }

    if(topum.getSinirlar().top > 600.0f){
        can--; 
        if(can <= 0){
            oyun_bitti_mi = true;
        } else {
            konumları_sıfırla();
        }
    }
}






void Oyun::konumları_sıfırla(){
    topum.resetle_top();
    raketim.resetle_raket();
}

void Oyun::ciz(){

    
    pencere.clear(Color(00,00,22)); // Her karede ekranı temizle eski izler kalmasın diye.


    if (!oyun_bitti_mi) {
    topum.ciz(pencere);   // Topu çizer.
    raketim.ciz(pencere); // Raketi çizer.

     for (auto& t : tuglalarim) {
        //Sadece kırılmamış olanları ekrana basar.
        if(!t.kirildi_mi) {
            t.ciz(pencere);
        }
    }
    anlik_skor_metni.setString("Puan: " + std::to_string(skor));
        pencere.draw(anlik_skor_metni);
    
    for (int i = 0; i < can; i++) {
            sf::Sprite gecici_kalp;
            gecici_kalp.setTexture(kalp_logosu);
            gecici_kalp.setScale(0.05f, 0.05f);
            gecici_kalp.setPosition(10.0f + (i * 35.0f), 10.0f);
            pencere.draw(gecici_kalp); 
        }
    } else {
        bitis_metni.setString("OYUN BITTI!\nToplam Skor: " + std::to_string(skor));
        pencere.draw(bitis_metni);

        yeniden_baslat_metni.setString("Tekrar oynamak icin 'E', cikmak icin 'H' basiniz.");
        pencere.draw(yeniden_baslat_metni);
        
    }
    
    pencere.display(); // Çizilenleri ekrana yansıtır.
}



void Oyun::oyunu_sıfırla(){
    can=3;
    skor=0;
    konumları_sıfırla();
    oyun_bitti_mi=false;


    for (auto& t : tuglalarim) {
        t.kirildi_mi = false;
        t.dayaniklilik = t.baslangic_cani; 
        
    }
}