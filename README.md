# YZM104 Programlama II - Breakout Oyunu

## Öğrenci Bilgileri

- Fatih Mutlu - 240229006
- Kocaeli Üniversitesi
- Mühendislik Fakültesi
- Yazılım Mühendisliği Bölümü

---

## Proje Açıklaması

Bu proje, C++ ve SFML kullanılarak geliştirilmiş modüler bir Breakout (Tuğla Kırma) oyunudur.

Projede nesne yönelimli programlama (OOP) prensipleri uygulanmış olup oyun sistemi farklı sınıflar halinde tasarlanmıştır. Oyuncu raketi kontrol ederek topun düşmesini engellemeye çalışır ve ekrandaki tüm tuğlaları kırarak seviyeleri tamamlamayı hedefler.

---

## Oyun Özellikleri

- Klavye kontrollü raket sistemi
- Gerçek zamanlı çarpışma sistemi (AABB)
- Procedural seviye üretimi
- Çok katmanlı tuğla hasar sistemi
- Skor sistemi
- Seviye sistemi
- Oyun sonu ekranı
- Modüler proje yapısı
- CMake destekli derleme sistemi

---

## Oyun Nasıl Oynanır?

Oyuncu ekranın alt kısmında bulunan raketi kontrol eder.

Top oyun alanında hareket eder ve tuğlalara çarparak onları kırar. Tüm tuğlalar temizlendiğinde bir sonraki seviyeye geçilir.

Top ekranın altından çıkarsa oyuncu bir can kaybeder. Tüm canlar tükendiğinde oyun sona erer.

Oyunun amacı mümkün olduğunca yüksek skor elde ederek seviyeleri tamamlamaktır.

### Kontroller

| Tuş | Görev |
|------|--------|
| ← | Raketi sola hareket ettirir |
| → | Raketi sağa hareket ettirir |
| ENTER | Oyunu yeniden başlatır |
| ESC | Oyundan çıkış yapar |

---

## Kullanılan Teknolojiler

| Teknoloji | Sürüm | Açıklama |
|------------|--------|-----------|
| C++ | C++17 | Oyun mantığı |
| SFML | 2.6.1 | Grafik ve giriş sistemi |
| GCC/G++ | 14.2.0 | Derleyici |
| Git | 2.54.0 | Versiyon kontrol |
| CMake | 3.10+ | Build sistemi |
| Visual Studio Code | Güncel | Geliştirme ortamı |
| MSYS2 UCRT64 | Güncel | Paket ve araç yönetimi |

---

## Proje Yapısı

```text
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
└── kalp.png
```

---

## Derleme ve Çalıştırma

### Gereksinimler

- C++17 destekli derleyici
- SFML 2.6.1
- CMake 3.10 veya üzeri
- Git

### Projeyi Klonlama

```bash
git clone https://github.com/fatihmutlu7777-byte/240229006_Fatih_Mutlu_Breakout.git
cd 240229006_Fatih_Mutlu_Breakout
```

### Derleme

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Çalıştırma

Windows:

```bash
./Breakout.exe
```

Linux / macOS:

```bash
./Breakout
```

> Not: Linux ve macOS sistemlerinde SFML kütüphanesinin sistem üzerinde kurulu olması gerekmektedir.

---

## GitHub Repo

https://github.com/fatihmutlu7777-byte/240229006_Fatih_Mutlu_Breakout

---

## Demo Video

https://drive.google.com/file/d/1AKDEgAd2od4gF2GsV-deK3ZspQfFYabD/view?usp=sharing