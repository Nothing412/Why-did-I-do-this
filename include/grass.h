#pragma once
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace std;
using namespace sf;


class Grass{
public:
    Grass(Vector2f p_position,int type);
    Sprite grass69;
    Texture texture69;
    IntRect intRect69;
    void draw(RenderWindow &window);
    //bool canDraw = true;
};

Grass::Grass(Vector2f p_position,int type){
    switch (type)
    {
    case 1:
        if(!texture69.loadFromFile("../Sprout Lands - Sprites - Basic pack/Objects/Grass.png")){
            cout << "error loading grass";
        }    
        intRect69 = IntRect(0,0,17,17);
        grass69.setPosition(p_position);
        grass69.setTexture(texture69);
        grass69.setScale(Vector2f(7,7));
        grass69.setTextureRect(intRect69);
    break;  
    }
}

void Grass::draw(RenderWindow &window){
    window.draw(grass69);
}