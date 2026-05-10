#ifndef RAKET_HPP
#define RAKET_HPP

#include <SFML/Graphics.hpp>
using namespace std;


class Raket{

private:
    sf::RectangleShape raketin_sekli;
    float raketin_hizi;

public:

    Raket();
    
    void guncelle();
    void ciz(sf::RenderWindow& pencere);
    void resetle();
    
    sf::FloatRect getSinirlar() { 
    return raketin_sekli.getGlobalBounds(); 
    }


    ~Raket() = default;

};




#endif 