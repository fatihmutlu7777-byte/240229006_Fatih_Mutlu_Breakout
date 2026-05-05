#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
using namespace std;

class Top {

private:
    sf::CircleShape top_sekli;
    sf::Vector2f top_hizi; 
    float top_yarıcapi;   
public:
    // Yapıcı fonksiyon artık başlangıç hızı ve yarıçapı da parametre olarak alabilir
    // Varsayılan değerler vererek esneklik sağlıyoruz
    Top(float x, float y, float x_hizi , float y_hizi , float yaricap );
    
    ~Top() = default;

    void update();
    void draw(sf::RenderWindow& t_window);
    void carpma();
    void carpma_ust_alt();
    sf::FloatRect getBounds() const;

       
};

#endif