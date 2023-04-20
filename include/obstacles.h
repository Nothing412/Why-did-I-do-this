#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<fstream>
#include<string>
using namespace sf;
using namespace std;

class obstacle{

public:
    obstacle(int type);
    Texture texture;
    Sprite obstacle69;
    IntRect ntts;
    Vector2f getScale();
    Vector2f posi;
    FloatRect intersec(){
        return obstacle69.getGlobalBounds();
    }
    float angel = 0;
    void setRotation(float p_angel);
    void draw(RenderWindow &window,  Vector2f position){
        obstacle69.setTexture(texture);
        obstacle69.setTextureRect(ntts);
        obstacle69.setPosition(position);
        obstacle69.setScale(Vector2f(10,10));
        window.draw(obstacle69);
    }
};

obstacle::obstacle(int type){
    obstacle69.setRotation(angel);
    if(!texture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
        cout << "Never gonna give you up\n";
    }
    obstacle69.setTextureRect(ntts);
    obstacle69.setScale(10,10);
    switch (type)
    {
        case 1:
            ntts = IntRect(0,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 2:
            ntts = IntRect(16,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 3:
            ntts = IntRect(32,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 4:
            ntts = IntRect(0,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 5:
            ntts = IntRect(16,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 6:
            ntts = IntRect(32,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 7:
            ntts = IntRect(0,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;
        
        case 8:
            ntts = IntRect(16,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 9:
            ntts = IntRect(32,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        /////////////                               
        //d/d/d/d/d/d/d/d//d
        /////////////                               
        case 10:
            ntts = IntRect(48,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 11:
            ntts = IntRect(48,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 12:
            ntts = IntRect(48,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;
        //type 3

        case 13:
            ntts = IntRect(64,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 14:
            ntts = IntRect(80,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 15:
            ntts = IntRect(96,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;
        
        case 16:
            ntts = IntRect(112,0,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 17:
            ntts = IntRect(64,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 18:
            ntts = IntRect(80,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 19:
            ntts = IntRect(96,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 20:
            ntts = IntRect(112,16,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 21:
            ntts = IntRect(64,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 22:
            ntts = IntRect(80,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 23:
            ntts = IntRect(96,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 24:
            ntts = IntRect(112,32,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 25:
            ntts = IntRect(64,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 26:
            ntts = IntRect(80,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 27:
            ntts = IntRect(96,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 28:
            ntts = IntRect(112,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        /////////////////////////////////////////////
        /////W/W/W/W//A/DASD/A/SDAS/DAS/D////////////
        /////////////////////////////////////////////

        case 29:
            ntts = IntRect(0,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;
        
        case 30:
            ntts = IntRect(16,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;

        case 31:
            ntts = IntRect(32,48,16,16);
            obstacle69.setTextureRect(ntts);
        break;
    }
}

Vector2f obstacle::getScale(){
    return obstacle69.getScale();
}

void obstacle::setRotation(float p_angel){
    angel = p_angel;
    obstacle69.setRotation(p_angel);
}
