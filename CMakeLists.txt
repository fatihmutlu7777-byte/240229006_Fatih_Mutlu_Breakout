cmake_minimum_required(VERSION 3.10)
project(Breakout_Baba_Pro)

set(CMAKE_CXX_STANDARD 17)

# Başlık dosyalarının olduğu klasörü tanıtıyoruz
include_directories(include)

# Kaynak dosyalarını açıkça listeliyoruz (src klasörü içindeler)
set(SOURCES 
    src/main.cpp 
    src/oyun.cpp 
    src/top.cpp 
    src/raket.cpp 
    src/tugla.cpp
)

# SFML'i bul
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Programı oluştur
add_executable(Breakout ${SOURCES})

# SFML'i programa bağla
target_link_libraries(Breakout sfml-graphics sfml-window sfml-system)