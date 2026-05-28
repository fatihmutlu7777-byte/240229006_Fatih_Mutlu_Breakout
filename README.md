# YZM104 Programlama II - Breakout Oyunu

## Öğrenci Bilgileri
- Fatih Mutlu - 240229006
- Kocaeli Üniversitesi - Yazılım Mühendisliği

## Proje Açıklaması

Bu proje, C++ ve SFML kullanılarak geliştirilmiş modüler bir Breakout (Tuğla Kırma) oyunudur.

Projede nesne yönelimli programlama prensipleri kullanılmış olup oyun sistemi farklı sınıflar halinde tasarlanmıştır.

## Özellikler

- Klavye kontrollü raket sistemi
- Gerçek zamanlı çarpışma sistemi
- Procedural seviye üretimi
- Çok katmanlı tuğla hasar sistemi
- Skor ve seviye sistemi
- Oyun sonu ekranı
- Modüler proje yapısı

## Kullanılan Teknolojiler

| Teknoloji | Açıklama |
|---|---|
| C++17 | Oyun mantığı |
| SFML 2.6.1 | Grafik sistemi |
| GCC 14.2.0 | Derleyici |
| Git & GitHub | Versiyon kontrol |
| CMake | Build sistemi |
| Visual Studio Code | IDE |

## Proje Yapısı

src/
 ├── main.cpp
 ├── oyun.cpp
 ├── top.cpp
 ├── raket.cpp
 ├── tugla.cpp
 ├── skor.cpp
 ├── seviye.cpp
 └── oyunsonu.cpp

include/
 ├── oyun.hpp
 ├── top.hpp
 ├── raket.hpp
 ├── tugla.hpp
 ├── skor.hpp
 ├── seviye.hpp
 └── oyunsonu.hpp

assets/
 ├── arial.ttf
 ├── catlak.png
 ├── kalp.png

## Derleme

```bash
mkdir build
cd build
cmake ..
make
```

## Çalıştırma

```bash
./Breakout
```

## GitHub Repo

https://github.com/fatihmutlu7777-byte/240229006_Fatih_Mutlu_Breakout

## Demo Video

https://drive.google.com/file/d/1AKDEgAd2od4gF2GsV-deK3ZspQfFYabD/view?usp=sharing
