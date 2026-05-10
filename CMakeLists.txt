cmake_minimum_required(VERSION 3.10)
project(240229006_Fatih_Mutlu_Breakout)

set(CMAKE_CXX_STANDARD 17)

# Başlık dosyalarının olduğu klasörü tanıtıyoruz.
include_directories(include)

# Kaynak dosyalarını açıkça listeliyoruz.
set(SOURCES 
    src/main.cpp 
    src/oyun.cpp 
    src/top.cpp 
    src/raket.cpp 
    src/tugla.cpp
)

# SFML'i bulur.
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Programı oluştur.
add_executable(Breakout ${SOURCES})

# SFML'i programa bağlar.
target_link_libraries(Breakout sfml-graphics sfml-window sfml-system)


# Ana dizindeki assets klasörünü, derlenen exe'nin (build) yanına kopyalar.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})