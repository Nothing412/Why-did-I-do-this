#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
using namespace sf;
using namespace std;

class house{
public:
    house(Vector2f p_position, RenderWindow &window);
    Vector2f position;
    Sprite house69;
    Texture houseTextureMap;
    bool is_inside = false;
    bool if_inside(){
        return is_inside;
    }
    void getInside(){
        if (is_inside){
            is_inside = false;
        }

        else{
            is_inside = true;
        }

    }
};

house::house(Vector2f p_position, RenderWindow &window){
    position = p_position;
    if(!houseTextureMap.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Wooden House.png")){
        cout << "Sussy baka\n";
    }
    house69.setTexture(houseTextureMap);
    house69.setPosition(position);
    house69.setScale(12,12);
    if(is_inside){
        cout << "you k";
    }
    window.draw(house69);
}