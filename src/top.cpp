#include "../include/Top.hpp"

Top::Top(float x, float y){//Topun özellikleri.
    top_hizi_x = 0.0f;
    top_hizi_y = 5.0f;
    top_yarıcapi = 5.0f;
    top_sekli.setRadius(top_yarıcapi);
    top_sekli.setOrigin(top_yarıcapi, top_yarıcapi); // Merkezi referans alır.
    top_sekli.setPosition(x, y);
    top_sekli.setFillColor(sf::Color::White);
}

void Top::guncelle() {//Topun sekmesini sağlar.
    
    top_sekli.move(top_hizi_x,top_hizi_y);

    if (top_sekli.getPosition().x <= 0 && top_hizi_x < 0) {
        top_hizi_x = -top_hizi_x;
    }
    
    
    if (top_sekli.getPosition().x >= 800 - 20 && top_hizi_x > 0) {
        top_hizi_x = -top_hizi_x;
    }
    
  
    if (top_sekli.getPosition().y <= 0 && top_hizi_y < 0) {
        top_hizi_y = -top_hizi_y;
    }
    
    
}

void Top::rakettensek(float raketMerkezi){//Topun raketten sekmesini sağlar.
    if(top_hizi_y>0){
        top_hizi_y=-top_hizi_y; // Yukarı fırlatcak.

        

        float TopMerkezi=top_sekli.getPosition().x + top_sekli.getRadius();


        float fark=TopMerkezi-raketMerkezi;

        top_hizi_x=fark*0.15f;
    }

}




void Top::resetle_top(){//Oyun bitiminde topun konumunu hızını resetler.
    top_sekli.setPosition(400.0f,300.0f);
    top_hizi_x=0.0f;
    top_hizi_y=5.0f;
}



void Top::resetle_top_can(){//Can eksilme durumunda topun konumunu hızını resetler.
    top_sekli.setPosition(400.0f,300.0f);
    top_hizi_x=0.0f;
}

void Top::ciz(sf::RenderWindow& pencere) {//Ekrana çizer.
    pencere.draw(top_sekli);
}




void Top::hiz_arttir(float carpan){//Topun hızını level atladıkça arttırır.
    top_hizi_y*=carpan;
}

void Top::tugladan_sek_x(){//Topun tuğladan sekmesini sağlar.
    top_hizi_x=-top_hizi_x;
}

void Top::tugladan_sek_y(){//Topun tuğladan sekmesini sağlar.
    top_hizi_y=-top_hizi_y;
}