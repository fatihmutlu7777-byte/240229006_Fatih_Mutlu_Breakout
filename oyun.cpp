#include "oyun.hpp"

Oyun::Oyun() 
    : m_window(sf::VideoMode(800, 600), "Breakout - Fatih Mutlu"),m_top(400.0f, 300.0f, 6.0f, 6.0f, 12.0f)
{
    m_window.setFramerateLimit(60);
}

void Oyun::run() {
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Oyun::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Oyun::update() {
    m_top.update();

    // Duvar çarpışma kontrolleri
    sf::FloatRect bounds = m_top.getBounds();
    if (bounds.left < 0 || bounds.left + bounds.width > 800) {
        m_top.carpma();
    }
    if (bounds.top < 0 || bounds.top + bounds.height > 600) {
        m_top.carpma_ust_alt();
    }
}

void Oyun::render() {
    m_window.clear();
    m_top.draw(m_window);
    m_window.display();
}