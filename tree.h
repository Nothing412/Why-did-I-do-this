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
    Texture texture69;
    Sprite tree69;
    IntRect IntRect69;
    FloatRect intersec(){
        return tree69.getGlobalBounds();
    }
    void treeMidbreak();
    void treeAlomstBreak();
    void treeSetDeafult();
    void treeBreak();
    void draw(RenderWindow &window);
};  

Tree::Tree(Vector2f p_position){
    if(!texture69.loadFromFile("Sprout Lands - Sprites - Basic pack/Objects/Tree.png")){
        cout << "error loading trees";
    }
    IntRect69 = IntRect(0,0,15,30);
    tree69.setPosition(p_position);
    tree69.setTexture(texture69);
    tree69.setScale(Vector2f(10,10));
    tree69.setTextureRect(IntRect69);
}

void Tree::draw(RenderWindow &window){
    window.draw(tree69);
}

void Tree::treeMidbreak(){
    IntRect69 = IntRect(37,0,15,30);
    tree69.setTextureRect(IntRect69);
}

void Tree::treeAlomstBreak(){
    IntRect69 = IntRect(20,0,15,30);
    tree69.setTextureRect(IntRect69);
}

void Tree::treeSetDeafult(){
    IntRect69 = IntRect(0,0,15,30);
    tree69.setTextureRect(IntRect69);
}