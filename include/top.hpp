#ifndef TOP_HPP
#define TOP_HPP
#include "top.hpp"

#include <SFML/Graphics.hpp>

class Top {
private:
    sf::CircleShape top_sekli;
    float top_hizi_x;
    float top_hizi_y;
    float top_yarıcapi;   

public:
    Top(float x, float y);
    ~Top() = default;

    void guncelle();
    void ciz(sf::RenderWindow& t_window);
    void rakettensek(float raketMerkezi);
    void tugladansek();

    
    sf::FloatRect getSinirlar() {        
        return top_sekli.getGlobalBounds(); 
    }
};

#endif // TOP_HPP