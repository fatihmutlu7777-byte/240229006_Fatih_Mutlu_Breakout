#ifndef RAKET_HPP
#define RAKET_HPP

#include <SFML/Graphics.hpp>



class Raket{

private:
    sf::RectangleShape raketin_sekli;
    float raketin_hizi;

public:

    Raket();
    
    void guncelle();
    void ciz(sf::RenderWindow& pencere);
    void resetle_raket();
    
    sf::FloatRect getSinirlar() { 
    return raketin_sekli.getGlobalBounds(); 
    }


    ~Raket() = default;

};




#endif 