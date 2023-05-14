#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
using namespace sf;
using namespace std;

void FenceUpdate(Sprite& fenceFarm,Sprite& player){
	if(player.getGlobalBounds().intersects(fenceFarm.getGlobalBounds())){
		
		if(player.getPosition().x>=-1182){
			player.setPosition(-1181,player.getPosition().y);
		}

		if(player.getPosition().x<=-2029.84){
			player.setPosition(-2028,player.getPosition().y);
		}
		if(player.getPosition().y<=625.975){
			player.setPosition(player.getPosition().x,624);
		}

		if(player.getPosition().y>=1294.72){
			player.setPosition(player.getPosition().x,1295);
		}

		if(Keyboard::isKeyPressed(Keyboard::E)){
			player.setPosition(player.getPosition().x,156.513);		
		}
	}
}