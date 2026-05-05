cmake_minimum_required(VERSION 3.10)


project(240229006_Fatih_Mutlu_Breakout)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


add_executable(Breakout 
    src/main.cpp 
    src/Top.cpp 
    src/Game.cpp
)

target_link_libraries(Breakout sfml-graphics sfml-window sfml-system)