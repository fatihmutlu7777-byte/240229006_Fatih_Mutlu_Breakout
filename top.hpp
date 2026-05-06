#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
using namespace std;

class Top {

private:
    sf::CircleShape top_sekli;
    float top_hizi_x;
    float top_hizi_y;
    
    float top_yarıcapi;   
public:
    
    Top(float x, float y);
    
    ~Top() = default;

    void update();
    void ciz(sf::RenderWindow& t_window);
    void carpma();
    void carpma_ust_alt();
    sf::FloatRect getBounds() const;

       
};

#endif