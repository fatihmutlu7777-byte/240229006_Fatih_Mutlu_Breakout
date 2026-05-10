# 240229006 - Fatih Mutlu - Breakout Game

Bu proje, Kocaeli Üniversitesi Yazılım Mühendisliği bölümü için geliştirilmiş, C++ ve SFML kütüphanesi kullanan bir tuğla kırma oyunudur.

## 🛠️ Teknik Özellikler
* **Dayanıklılık Sistemi:** Tuğlalar katmanlarına göre 1 ile 4 vuruş arasında kırılır.
* **Dinamik Çatlaklar:** Tuğlalar hasar aldığında rastgele açılarla dönen çatlak görseli belirir.
* **Can Sistemi:** Oyuncunun 3 canı vardır ve sol üstteki kalp sprite'ları ile takip edilir.
* **Kaynak Yönetimi:** `static sf::Texture` kullanılarak bellek optimizasyonu yapılmıştır.

## 🚀 Kurulum ve Çalıştırma
1. `build` klasörüne girin: `cd build`
2. Derleyin: `cmake --build .`
3. Çalıştırın: `./Breakout.exe`