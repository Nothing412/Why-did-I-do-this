#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include"include/json/value.h"
#include"include/json/json.h"
#include<fstream>
#include<string>
using namespace sf;
using namespace std;

class house{
public:
    house(Vector2f p_position, RenderWindow &window);
    Vector2f position;
    Sprite house69;
    Texture houseTextureMap;
    IntRect sass;
    float angel;
    bool is_inside = true;
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
    Vector2f getScale(){
        return house69.getScale() + Vector2f(house69.getTextureRect().width,house69.getTextureRect().height);
    }

    FloatRect intersec(){
        return house69.getGlobalBounds();
    }
};

house::house(Vector2f p_position, RenderWindow &window){
    position = p_position;
    if(!houseTextureMap.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Wooden House 2.png")){
        cout << "Sussy baka\n";
    }
    house69.setTexture(houseTextureMap);
    house69.setPosition(position);
    house69.setScale(12,12);
    if(is_inside){
        sass = IntRect(26,0,26,50);
        house69.setTextureRect(sass);
        house69.setScale(30 ,20);
        house69.setRotation(angel);
        window.draw(house69);
    }
}

