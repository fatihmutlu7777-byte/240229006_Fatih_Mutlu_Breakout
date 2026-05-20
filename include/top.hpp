#ifndef TOP_HPP
#define TOP_HPP

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
    void tugladan_sek_x();
    void tugladan_sek_y();
    void resetle_top();
    void hiz_arttir(float carpan);

    
    sf::FloatRect getSinirlar() {        
        return top_sekli.getGlobalBounds(); 
    }
};

#endif 