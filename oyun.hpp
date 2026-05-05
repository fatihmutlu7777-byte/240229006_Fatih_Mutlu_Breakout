#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Top.hpp"

class Oyun {

private:
    void processEvents();
    void update();
    void render();

public:
    Oyun();
    void run(); // Oyunun ana döngüsü burada döner


    sf::RenderWindow m_window;
    Top m_top; // Top nesnesini burada tutuyoruz
};

#endif