YZM104 Programlama II - Oyun Projesi: Breakout
Öğrenci: Fatih Mutlu - 240229006
Bölüm: Yazılım Mühendisliği, Kocaeli Üniversitesi

Bu proje, C++ ve SFML kütüphanesi kullanılarak geliştirilmiş dinamik bir "Breakout / Tuğla Kırma" oyunudur. Proje, nesne yönelimli programlama (OOP) prensiplerine uygun olarak tasarlanmış olup modüler bir dosya hiyerarşisine (src, include, assets) sahiptir.

🚀 Proje Özellikleri ve Mekanikler
Özgün Seviye Üretimi (Asal Sayı Hash Motoru): Bölüm tasarımları statik dizilerden çekilmez; matematiksel bir karma (hash) formülüyle her seviyede benzersiz dizilimler oluşturulur.

Katmanlı Hasar ve Kırılma Fiziği: Tuğlalar aldıkları hasara göre farklı açılarda dinamik çatlak görselleri (texture) yükler.

Hassas Çarpışma ve Sekme (AABB): Topun rakete çarptığı noktaya göre x ve y eksenindeki sekme ivmesi matematiksel olarak hesaplanır.

Optimizasyon: Bellek sızıntılarını önlemek amacıyla Font ve Texture gibi ağır kaynaklar yöneticiler tarafından tek bir kez yüklenip (Bağımlılık Enjeksiyonu) ilgili sınıflara referans olarak dağıtılır.

🎮 Kontroller
Sol Yön Tuşu / Sağ Yön Tuşu: Raketi hareket ettirir.

ENTER: Oyun bittiğinde veya kazanıldığında yeniden başlatır.

ESC: Oyundan çıkış yapar.

🛠️ Sistem Gereksinimleri
Projeyi kendi bilgisayarınızda derleyip çalıştırabilmeniz için aşağıdaki araçların sisteminizde kurulu olması ve sistem yoluna (PATH) eklenmiş olması gerekmektedir:

Git (Projeyi klonlamak için)

CMake (Minimum sürüm 3.10)

C++ Derleyicisi (C++17 destekli, örn: MinGW, GCC veya MSVC)

SFML Kütüphanesi (Sürüm 2.5 veya üzeri, CMake'in bulabileceği şekilde yapılandırılmış olmalıdır)

⚙️ Kurulum ve Derleme Adımları
Aşağıdaki komutları sırasıyla terminalinizde (veya Komut İstemcisi / PowerShell) çalıştırarak projeyi derleyebilirsiniz.

1. Projeyi Bilgisayarınıza Klonlayın

Bash
git clone <GITHUB_REPO_LINKIN>
2. Proje Dizinine Girin

Bash
cd BREAKOUT_PROJE
3. Derleme (Build) Klasörü Oluşturun ve İçine Girin

Bash
mkdir build
cd build
4. CMake Yapılandırmasını Başlatın

Bash
cmake ..
Not: Windows üzerinde MinGW kullanıyorsanız ve üstteki komut hata verirse şu komutu kullanın: cmake -G "MinGW Makefiles" ..

5. Projeyi Derleyin

Bash
cmake --build .
6. Oyunu Çalıştırın
Derleme tamamlandıktan sonra, assets klasörü CMake tarafından otomatik olarak çalıştırılabilir dosyanın yanına kopyalanacaktır. Oyunu başlatmak için:

Windows için:

Bash
./Breakout.exe
Linux / macOS için:

Bash
./Breakout
📺 Demo Video
https://drive.google.com/file/d/1AKDEgAd2od4gF2GsV-deK3ZspQfFYabD/view?usp=sharing
[Projenin oynanış videosunu izlemek için buraya tıklayın] (Demo video linki olacak henüz yok.)