#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"vars.hpp"
#include"house.h"
#include<SFML/System.hpp>
#include"include/json/value.h"
#include"include/json/json.h"
#include<fstream>
#include<string>
#include<vector>
using namespace sf;
using namespace std;
//16 types

class Fence{
public:
    Fence(int type, Vector2f position,RenderWindow  &window);
    Sprite fence69;
    Texture texture69;
    IntRect rect69;
    void draw(RenderWindow &window);
    FloatRect intersec(){
        return fence69.getGlobalBounds();
    }

    void setRotation(float angle){
        fence69.setRotation(angle);
    }
};

Fence::Fence(int type, Vector2f position,RenderWindow  &window){
    switch (type){
    case 1:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(0,0,15,45);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 2:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(0,45,15,45);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 3:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(15,0,50,45);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 4:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(15,0,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 5:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(31,0,18,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 6:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(45,0,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 7:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(15,15,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 8:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(31,15,18,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 9:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(45,15,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 10:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(15,15,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 11:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(45,30,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 12:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(15,45,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 13:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(31,45,18,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;

    case 14:
        if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Fences.png")){
            cout << "Error loading texture 69\n";
        }
        fence69.setTexture(texture69);
        fence69.setPosition(position);
        rect69 = IntRect(45,45,15,15);
        fence69.setTextureRect(rect69);
        fence69.setScale(10,10);
    break;
    }
}

void Fence::draw(RenderWindow &window){
    window.draw(fence69);
}