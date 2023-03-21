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
};

obstacle::obstacle(int type , Vector2f position,RenderWindow &window){
    switch (type)
    {
    case 1:
        ntts = IntRect(3,0,22,22);
        if(!texture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
            cout << "Never gonna give you up";
        }
        obstacle69.setTexture(texture);
        obstacle69.setScale(7,7);
        obstacle69.setTextureRect(ntts);
        window.clear();
        window.draw(obstacle69);
        window.display();
        break;
    }
}
