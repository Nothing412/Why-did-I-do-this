#pragma once
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace std;
using namespace sf;

class Tree{
public:
    Tree(Vector2f p_position);
    Sprite tree69;
    Texture treeTexture;
    IntRect IntRect69;  
    void treeMidbreak();
    void treeAlomstBreak();
    void treeSetDeafult();
    void draw(RenderWindow &window);
    void deleteKindOf();
    void show();
    int time = 0;
    FloatRect intersec(){
        return tree69.getGlobalBounds();
    }
};

Tree::Tree(Vector2f p_position){
    if(!treeTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Objects/Tree.png")){
        cout << "klk;";
    }   
    IntRect69 = IntRect(0,0,15,30);
    tree69.setScale(Vector2f(8,8));
    tree69.setPosition(p_position);
    tree69.setTexture(treeTexture);
    tree69.setTextureRect(IntRect69);
}

void Tree::treeMidbreak(){
    IntRect69 = IntRect(20,0,15,30);
    tree69.setTextureRect(IntRect69);
}

void Tree::treeSetDeafult(){
    IntRect69 = IntRect(0,0,15,30);
    tree69.setTextureRect(IntRect69);
}

void Tree::treeAlomstBreak(){
    IntRect69 = IntRect(53,0,15,30);
    tree69.setTextureRect(IntRect69);
}

void Tree::draw(RenderWindow &window){
    window.draw(tree69);
}

void Tree::deleteKindOf(){
    tree69.setColor(Color::Transparent);
}

void Tree::show(){
    tree69.setColor(Color::White);
}