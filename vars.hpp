#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
using namespace sf;
using namespace std;
//this file is for variblus
/*bool can_move = true;
float playerPositionX;
float playerPositionY;
//Sprite mat texture 1
Texture sprite_map_1;*/
//scale  = x=6,y=6
//formula origin pos.x + size.x
//size = 22,22
//pos = 3,0 tof row
class obstacle{
private:
    /* data */
public:
    obstacle(int type, Vector2f position, RenderWindow &window);
    Texture texture;
    Sprite obstacle69;
    IntRect ntts;
    Vector2f getScale();
};

obstacle::obstacle(int type , Vector2f position,RenderWindow &window){
    switch (type)
    {
    case 1:
        ntts = IntRect(3,0,23,22);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setPosition(position);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.draw(obstacle69);
    break;

    case 2:
        ntts = IntRect(23,0,23,22);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setPosition(position);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.draw(obstacle69);
    break;

    case 3:
        ntts = IntRect(3,22,23,23);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setPosition(position);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.draw(obstacle69);
    break;

    case 4:
        ntts = IntRect(22,22,23,23);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setPosition(position);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.draw(obstacle69);
    break;

    case 5:
        ntts = IntRect(50,0,13,23);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setPosition(position);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.draw(obstacle69);
    break;

    case 6:
        ntts = IntRect(50,23,13,23);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setPosition(position);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.draw(obstacle69);
    break;  
    }
}

Vector2f obstacle::getScale(){
    return obstacle69.getScale();
}

