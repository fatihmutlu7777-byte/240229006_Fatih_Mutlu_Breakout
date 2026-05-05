#include "oyun.hpp"
using namespace sf;

// Yapıcı Fonksiyon: Pencereyi açar ve başlangıç ayarlarını yapar başlangıçta direk verdiğimiz değerlerde oluşsun diye ':' şeklinde yaparız '{}' yapmak yerine performansı arttırır
Oyun::Oyun() 
    : pencere(VideoMode(800.0f, 600.0f), "Breakout - Fatih Mutlu"),topum(400.0f, 450.0f) // Topu ekranın ortasına koymuş olduk
{
    pencere.setFramerateLimit(60); // Oyunun çok hızlı akmaması için 60 FPS'e sabitledik

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
}

void Oyun::ciz() {
    pencere.clear(); // Her karede ekranı temizle eski izler kalmasın diye

    topum.draw(pencere);   // Topu çizer
    raketim.ciz(pencere); // Raketi çizer

    pencere.display(); // Çizilenleri ekrana yansıtır
}