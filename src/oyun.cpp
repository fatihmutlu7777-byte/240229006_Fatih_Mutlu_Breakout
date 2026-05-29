#include "../include/oyun.hpp"
#include <ctime>
using namespace sf;




// Yapıcı Fonksiyon: Pencereyi açar ve başlangıç ayarlarını yapar başlangıçta direk verdiğimiz değerlerde oluşsun diye ':' şeklinde yaparız '{}' yapmak yerine performansı arttırır.
Oyun::Oyun() 
    : pencere(VideoMode(800.0f, 600.0f), "Breakout - Fatih Mutlu"),seviye_ekranim(15.0f,50.0f),topum(400.0f, 450.0f),can(3),oyun_bitti_mi(false),oyunsonu_ekranim(400.0f,300.0f),skor_ekranim(15.f,30.f)// Topu ekranın ortasına koymuş olduk.
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
    
    skor_ekranim.fontu_ayarla(font);
    seviye_ekranim.fontu_ayarla(font);
    oyunsonu_ekranim.fontu_ayarla(font);

    tuglalari_diz();

   
}






void Oyun::tuglalari_diz() {
    tuglalarim.clear(); 

    int anlik_seviye = seviye_ekranim.getseviye();

   
    // %100 TEKRARSIZ "ASAL SAYI HASH" MOTORU 
    
    
    
    // 83 asal sayısı ile seviyeyi çarpıp 144'e bölüyoruz. 
    // Bu bize 0 ile 143 arasında rastgele görünen ama asla tekrar etmeyen bir 'id' verir.
    int id = (anlik_seviye * 83) % 144; 

    // O id'yi parçalayıp haritamızın özelliklerini belirliyoruz:
    int ana_desen  = id % 8;                 // 8 farklı şekil
    int p1         = (id / 8) % 3 + 1;       // 1, 2 veya 3 çarpanı
    int p2         = (id / 24) % 3;          // 0, 1 veya 2 kayma mesafesi
    bool ters_cevir= (id / 72) % 2 == 0;     // Düz mü, ters mi?

    // Renklerimiz
    sf::Color satirRenkleri[5] = {
        sf::Color::Red, sf::Color(255, 165, 0), sf::Color::Yellow, 
        sf::Color::Green, sf::Color::Cyan
    };

    for (int i = 0; i <= 4; i++) { 
        for (int j = 0; j < 10; j++) { 

            // 1. BOŞLUK VE KAPI ALGORİTMASI
            if (i == 5) {
                // Taktiksel Koridorumuz 
                if (j >= 3 && j <= 6) continue; 
            } 
            else {
                bool bosluk_koy = false;
                
                int j_simetrik = (j < 5) ? j : 9 - j; 
                int i_hesap = ters_cevir ? (4 - i) : i;

                // Seçilen benzersiz parametrelerle harita çizimi:
                switch (ana_desen) {
                    case 0: 
                        if ((i_hesap + j_simetrik) % (p1 + 1) == p2) bosluk_koy = true;
                        break;
                    case 1: 
                        if (i_hesap % p1 == p2) bosluk_koy = true;
                        break;
                    case 2: 
                        if (j_simetrik % p1 == p2) bosluk_koy = true;
                        break;
                    case 3: 
                        if (i_hesap > j_simetrik + p2) bosluk_koy = true;
                        break;
                    case 4: 
                        if (i_hesap + j_simetrik < 3 + p2) bosluk_koy = true;
                        break;
                    case 5: 
                        if (abs(i_hesap - j_simetrik) > p1 && abs(i_hesap + j_simetrik - 4) > p1) bosluk_koy = true;
                        break;
                    case 6: 
                        if (abs(i_hesap - 2) + abs(j_simetrik - 2) <= p1) bosluk_koy = true;
                        break;
                    case 7: 
                        if ((i_hesap - j_simetrik + 5) % (p1 + 1) == p2) bosluk_koy = true;
                        break;
                }

                if (bosluk_koy) continue; 
            }

            // 2. KOORDİNAT HESAPLAMALARI
            float tugla_genislik = 60.0f;
            float tugla_yukseklik = 20.0f;
            
            float xPozisyonu = 55.0f + (j * 70.0f); 
            float yPozisyonu = 80.0f + (i * 35.0f); 

            // 3. RENK VE CAN ATAMALARI
           
            if(i>=0){

            
                int tugla_cani;
                if(i>=4){
                    tugla_cani=1;
                } 
                else if((i<4)&&(i>=3)){
                    tugla_cani=1;
                }
                else {tugla_cani = 2;}

                tuglalarim.push_back(Tugla(xPozisyonu, yPozisyonu, tugla_genislik, tugla_yukseklik, satirRenkleri[i], tugla_cani));
            }
        }
    }

    // İşimiz bitince oyunun genel rastgeleliği (top sekmesi vb.) bozulmasın diye sıfırlıyoruz.
    srand(static_cast<unsigned>(time(0))); 
}




void Oyun::yeni_seviye_yukle(){
    
    konumları_sıfırla();
    tuglalari_diz();
    topum.hiz_arttir(1.3f);//Topun hızı artar.

   
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
        sf::FloatRect kesisim;
        if (!t.kirildi_mi && topum.getSinirlar().intersects(t.getSinirlar(),kesisim)) {
            if(t.baslangic_cani!=-1){
            t.darbe_al();
            if (t.kirildi_mi) {
                skor_ekranim.skor_ekle(1);
            }
        }
            if(kesisim.width < kesisim.height){
                topum.tugladan_sek_x();
            }
            else{
                topum.tugladan_sek_y();
            }
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
        seviye_ekranim.seviye_ekle(1);
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
            oyunsonu_ekranim.seviyeyi_ayarla(seviye_ekranim.getseviye());

        } else {
            topum.resetle_top_can();
            raketim.resetle_raket();
          
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


    if(!oyun_bitti_mi){
    skor_ekranim.ciz(pencere);
    seviye_ekranim.ciz(pencere);
    }

    if(oyun_bitti_mi){
        oyunsonu_ekranim.ciz(pencere);

    }
    pencere.display(); // Çizilenleri ekrana yansıtır.
}





void Oyun::oyunu_sıfırla(){
    oyun_bitti_mi=false;
    can=3;
    skor_ekranim.skoru_sifirla();


    seviye_ekranim.seviyeyi_sifirla();
    skor_ekranim.skoru_sifirla();
    
    konumları_sıfırla();
    tuglalari_diz();
   

    for (auto& t : tuglalarim) {
        t.kirildi_mi = false;
        t.dayaniklilik = t.baslangic_cani; 
        
    }
}