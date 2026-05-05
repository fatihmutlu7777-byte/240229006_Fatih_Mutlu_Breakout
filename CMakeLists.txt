cmake_minimum_required(VERSION 3.10)

# Proje adı
project(BreakoutGame)

# Modern C++ standardının belirlenmesi
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# SFML kütüphanelerinin sistemde bulunması
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Yürütülebilir (executable) dosyanın tanımlanması
add_executable(Breakout main.cpp)

# SFML kütüphanelerinin projeye bağlanması
target_link_libraries(Breakout sfml-graphics sfml-window sfml-system)