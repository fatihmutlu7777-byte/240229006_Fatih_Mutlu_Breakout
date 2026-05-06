#include "../include/oyun.hpp"
using namespace sf;

// Yapıcı Fonksiyon: Pencereyi açar ve başlangıç ayarlarını yapar başlangıçta direk verdiğimiz değerlerde oluşsun diye ':' şeklinde yaparız '{}' yapmak yerine performansı arttırır
Oyun::Oyun() 
    : pencere(VideoMode(800.0f, 600.0f), "Breakout - Fatih Mutlu"),topum(400.0f, 450.0f) // Topu ekranın ortasına koymuş olduk
{
    pencere.setFramerateLimit(60); // Oyunun çok hızlı akmaması için 60 FPS'e sabitledik


    // 8 farklı küme için 2x4'lük bir renk matrisi oluşturuyoruz
sf::Color kumeRenkleri[2][4] = {
    {sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan},
    {sf::Color(163,66,86), sf::Color(255, 165, 0), sf::Color(0,153,76), sf::Color(255, 0, 0)},
    
};

// Toplam 8 satır ve 20 sütunluk döngü
for (int i = 0; i < 8; i++) { 
    for (int j = 0; j < 20; j++) { 
        
        // 1. STANDART ARALIK HESABI 
        float xPozisyonu = j * 25.0f; 
        float yPozisyonu = i * 25.0f; 

        // 2. DİKEY KORİDORLAR (Sütunları 4 Kümeye Ayırma)
        if (j >= 5) xPozisyonu += 40.0f; 
        if (j >= 10) xPozisyonu += 40.0f; 
        if (j >= 15) xPozisyonu += 40.0f; 

        // 3. YATAY KORİDORLAR (Satırları 2 Kümeye Ayırma)
        if (i >= 4) yPozisyonu += 40.0f; 
       

        // 4. EKRAN BAŞLANGIÇ NOKTALARI
        xPozisyonu += 92.5f; 
        yPozisyonu += 50.0f; 

        // 5. KÜME RENGİNİ TESPİT ETME (Mantıksal Gruplama)
        // C++ tam sayıları bölerken ondalıkları atar. 
        // Örneğin j=0,1,2,3,4 için (j/5) her zaman 0 sonucunu verir.
        int kumeSatiri = i / 4; // 0, 1 veya 2 değerini üretir
        int kumeSutunu = j / 5; // 0, 1, 2 veya 3 değerini üretir
        
        // Matristen ilgili rengi seç
        sf::Color gecerliRenk = kumeRenkleri[kumeSatiri][kumeSutunu];

        // 6. TUĞLAYI OLUŞTUR VE LİSTEYE EKLE (Rengi parametre olarak yolluyoruz)

        tuglalarim.push_back(Tugla(xPozisyonu, yPozisyonu, 20.0f, 20.0f, gecerliRenk)); 
    }
}

}

void Oyun::calistir() {
    // Oyunun ana döngüsü
    while (pencere.isOpen()) {
        olaylari_isle();
        guncelle();
        ciz();
    }
}

void Oyun::olaylari_isle() {
    sf::Event olay;
    while (pencere.pollEvent(olay)) {
        if (olay.type == sf::Event::Closed)
            pencere.close();
    }
}

void Oyun::guncelle() {
    // 1. Nesnelerin kendi hareketleri
    topum.update();     // Topun ilerlemesi ve duvarlardan sekmesi gibi
    raketim.guncelle(); // Topun hareketini günceller

    // 2. Çarpışma Kontrolü (Top raketten seksin mi?)
    // Topun sınırları ile raketin sınırları kesişiyor mu bakıyoruz
    if (topum.getBounds().intersects(raketim.getBounds())) {
        topum.carpma_ust_alt(); // Bu işlem topu yukarı sektir
    }

    // 3. Ekran Sınır Kontrolleri topumuz ekran arası ilişki
    sf::FloatRect top_sinir = topum.getBounds();
    
    // Yan duvarlar
    if (top_sinir.left < 0 || top_sinir.left + top_sinir.width > 800) {
        topum.carpma();
    }
    
    // Üst duvar
    if (top_sinir.top < 0) {
        topum.carpma_ust_alt();
    }

    // Alt duvar (Top yere düşerse - Şimdilik sadece sektiyor, sonra can azaltma eklenecek)
    if (top_sinir.top + top_sinir.height > 600) {
        topum.carpma_ust_alt(); 
    }


    for (auto& t : tuglalarim) {
        
        if(!t.kirildi_mi && topum.getBounds().intersects(t.getSinirlar())){ // Burda top tuğla sınırlarına çarpmışmı baılır eğer true dönerse aşağıda tuğlaları kaldırma işlemi olur ardından top -hız_y olur ve break yapıp döngüyü bitiririz yoksa sonsuz döngü olup hepsini silebilir
            t.kirildi_mi=true;
    
        topum.carpma();
        topum.carpma_ust_alt();
        break;
            }
    }
}

void Oyun::ciz(){
    pencere.clear(Color(00,00,22)); // Her karede ekranı temizle eski izler kalmasın diye

    topum.ciz(pencere);   // Topu çizer
    raketim.ciz(pencere); // Raketi çizer

     for (auto& t : tuglalarim) {
        //Sadece kırılmamış olanları ekrana basar
        if(!t.kirildi_mi) {
            t.ciz(pencere);
        }
    }
    

    pencere.display(); // Çizilenleri ekrana yansıtır
}