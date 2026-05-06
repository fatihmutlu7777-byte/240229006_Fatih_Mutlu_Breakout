cmake_minimum_required(VERSION 3.10)
project(240229006_Fatih_Mutlu_Breakout)

# C++ Standartını 17 olarak belirttik
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tüm kaynak dosyalarını buraya eklenir

set(SOURCES 
    main.cpp 
    oyun.cpp 
    top.cpp 
    raket.cpp 
    tugla.cpp
)

# SFML kütüphaneleri bulunur
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Çalıştırılabilir dosya oluşturulur
add_executable(Breakout ${SOURCES})

# SFML kütüphanelerini projeye bağlanır
target_link_libraries(Breakout sfml-graphics sfml-window sfml-system)

# Include klasörü tanıtılır
target_include_directories(Breakout PUBLIC .)