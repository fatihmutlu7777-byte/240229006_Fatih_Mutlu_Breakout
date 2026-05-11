#include "../include/oyun.hpp"
#include <ctime>
using namespace sf;




// Yapıcı Fonksiyon: Pencereyi açar ve başlangıç ayarlarını yapar başlangıçta direk verdiğimiz değerlerde oluşsun diye ':' şeklinde yaparız '{}' yapmak yerine performansı arttırır.
Oyun::Oyun() 
    : pencere(VideoMode(800.0f, 600.0f), "Breakout - Fatih Mutlu"),mevcut_seviye(1),topum(400.0f, 450.0f),can(3),skor(0),oyun_bitti_mi(false),oyunsonu_ekranim(400.0f,300.0f),skor_ekranim(15.f,30.f)// Topu ekranın ortasına koymuş olduk.
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

    tuglalari_diz();

   
}




void Oyun::tuglalari_diz(){
     // 8 farklı küme için 2x4'lük bir renk matrisi oluşturuyoruz.
sf::Color kumeRenkleri[2][4] = {
    {sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan},
    {sf::Color(163,66,86), sf::Color(255, 165, 0), sf::Color(0,153,76), sf::Color(255, 0, 0)},
    
};

// Toplam 8 satır ve 20 sütunluk döngü.
for (int i = 0; i < 9; i++) { 
        for (int j = 0; j < 20; j++) { 
            float xPozisyonu = (j * 25.0f) + 92.5f; 
            float yPozisyonu = (i * 25.0f) + 50.0f; 

            if (j >= 5) xPozisyonu += 40.0f; 
            if (j >= 10) xPozisyonu += 40.0f; 
            if (j >= 15) xPozisyonu += 40.0f; 
            if (i >= 4) yPozisyonu += 40.0f; 


            int tugla_cani;
            sf::Color gecerliRenk;
            if(i==8){
                gecerliRenk=sf::Color(128, 128, 128);
                tugla_cani=-1;
            }
            else{


            int kumeSatiri = i / 4; 
            int kumeSutunu = j / 5; 
            gecerliRenk = kumeRenkleri[kumeSatiri][kumeSutunu];

           
            int satir_ıd_x = i % 4; //Satırları bulduk.


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

        
            }

            if(i!=8){
            tuglalarim.push_back(Tugla(xPozisyonu, yPozisyonu, 20.0f, 20.0f, gecerliRenk, tugla_cani));
            }
            else{
            tuglalarim.push_back(Tugla(xPozisyonu, yPozisyonu, 20.0f, 10.0f, gecerliRenk, tugla_cani));

            }
        }
    }
}


void Oyun::yeni_seviye_yukle(){
    mevcut_seviye++;
    konumları_sıfırla();
    tuglalari_diz();
    topum.hiz_arttir(1.1f);

   
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
            if (olay.key.code == sf::Keyboard::Enter) {
                oyunu_sıfırla(); 
            } else if (olay.key.code == sf::Keyboard::Escape) {
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
            if(t.baslangic_cani!=-1){
            t.darbe_al();
            if (t.kirildi_mi) {
                skor_ekranim.skor_ekle(1);
            }
        }
            topum.tugladansek();
            break; 
        }
    }

    bool seviye_bitti_mi=true;
    for (auto& t : tuglalarim) {
        if (t.baslangic_cani != -1 && !t.kirildi_mi) { // Bütün tuğlalar kırıldımı diye kontrol ama en alttaki kırılmaz tuğlaları görmezden geliyoruz.
            seviye_bitti_mi = false; 
            break; 
        }
    }

    if(seviye_bitti_mi){
        yeni_seviye_yukle();
    }

        
    if(topum.getSinirlar().intersects(raketim.getSinirlar())){ //Topun sınırı raketin sınırıyla kesiştimi demek.
       
        float RaketMerkezi=raketim.getSinirlar().left +(raketim.getSinirlar().width / 2.0f); // 2 ye bölüyoz çünü merkezini eklicez x in başlangıcına böylece tam orta nokta bulcaz neden .left yaptık çünkü SFML de right yok left top width height var right yapıncada açılıyo çalışıyor ama hata veriyor neden burda yaptık burası yönetici topu değiştircez top.c++ da yapsam include lar ve fazla fonksyonlar gerekicekti bizde yöneticide yaptık ara işlemi ve değeri top.c++ a aktardık.
        
        topum.rakettensek(RaketMerkezi);// Merkeze göre nasıl sektiği merkez koordinatını veririz buna göre ne kadar sapma varsa -hız_x ona göre belirlenir sekmede.
    }

    if(topum.getSinirlar().top > 600.0f){
        can--; 
        if(can <= 0){
            oyun_bitti_mi = true;
            oyunsonu_ekranim.skoru_ayarla(skor_ekranim.getskor());
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
   
    
    for (int i = 0; i < can; i++) {
            sf::Sprite gecici_kalp;
            gecici_kalp.setTexture(kalp_logosu);
            gecici_kalp.setScale(0.05f, 0.05f);
            gecici_kalp.setPosition(10.0f + (i * 35.0f), 10.0f);
            pencere.draw(gecici_kalp); 
        }
    }

    skor_ekranim.ciz(pencere);

    if(oyun_bitti_mi){
        oyunsonu_ekranim.ciz(pencere);

    }
    pencere.display(); // Çizilenleri ekrana yansıtır.
}



void Oyun::oyunu_sıfırla(){
    can=3;
    skor=0;
    mevcut_seviye=1;
    skor_ekranim.skoru_sifirla();
    konumları_sıfırla();
    tuglalari_diz();
    oyun_bitti_mi=false;


    for (auto& t : tuglalarim) {
        t.kirildi_mi = false;
        t.dayaniklilik = t.baslangic_cani; 
        
    }
}