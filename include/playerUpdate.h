#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace std;
using namespace sf;

void playerUpdate(Sprite& player , float dt , Texture& playerTexture , Texture& playerTextureAxe , int ss ,bool &is_hit){
    
    if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.move(-500 * dt, 0);
		player.setTexture(playerTexture);
		player.setTextureRect(IntRect(10, 106,ss, 30));
	}

	else if (Keyboard::isKeyPressed(Keyboard::D)){
		player.move(500 * dt, 0);
		player.setTexture(playerTexture);
		player.setTextureRect(IntRect(10, 154, ss, 30));
	}

	else if (Keyboard::isKeyPressed(Keyboard::W)){
		player.move(0, -500 * dt);
		player.setTexture(playerTexture);
		player.setTextureRect(IntRect(10, 57, ss, 30));
	}

	else if (Keyboard::isKeyPressed(Keyboard::S)){
		player.move(0, 500 * dt);
		player.setTexture(playerTexture);
	}

	else if(Mouse::isButtonPressed(Mouse::Left)){
		player.setTexture(playerTextureAxe);
		player.setTextureRect(IntRect(10,251,30,30));
		is_hit = true;
	}

	else{
		player.setTexture(playerTexture);
		player.setTextureRect(IntRect(10, 10, ss, 30));	
		is_hit = false;
	}
}