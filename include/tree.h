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
    vector<Sprite> tree = {
        Sprite()
    };
    Texture treeTexture;
    IntRect IntRect69;  
    void treeMidbreak();
    void treeAlomstBreak();
    void treeSetDeafult();
    void draw(RenderWindow &window);
    int time = 0;
    FloatRect intersec(){
        return tree[0].getGlobalBounds();
    }
};

Tree::Tree(Vector2f p_position){
    if(!treeTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Objects/Tree.png")){
        cout << "klk;";
    }   
    IntRect69 = IntRect(0,0,15,30);
    tree[0].setScale(Vector2f(8,8));
    tree[0].setPosition(p_position);
    tree[0].setTexture(treeTexture);
    tree[0].setTextureRect(IntRect69);
}

void Tree::treeMidbreak(){
    IntRect69 = IntRect(53,0,15,30);
    tree[0].setTextureRect(IntRect69);
}

void Tree::treeSetDeafult(){
    IntRect69 = IntRect(0,0,15,30);
    tree[0].setTextureRect(IntRect69);
}

void Tree::treeAlomstBreak(){
    IntRect69 = IntRect(20,0,15,30);
    tree[0].setTextureRect(IntRect69);
}

void Tree::draw(RenderWindow &window){
    window.draw(tree[0]);
}
