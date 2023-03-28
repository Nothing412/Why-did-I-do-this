#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"vars.hpp"
#include"house.h"
#include<SFML/System.hpp>
#include<vector>
using namespace sf;
using namespace std;

int main(){
	RenderWindow window(VideoMode(800,800),"Cat woodcutter", Style::Fullscreen);
	window.setFramerateLimit(60);
	Texture sprite_map_1;
	if(!sprite_map_1.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
		cout << "Erorr sprite map 1\n";
	}
	Image icon;
	icon.loadFromFile("icon.png");

	window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
	
	Sprite player;
	Texture playerTexture;
	if(!playerTexture.loadFromFile("Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Spritesheet.png")){
		cout << "Axe textureure failure";
	}
	Texture playerTextureAxe;
	if(!playerTextureAxe.loadFromFile("Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions.png")){
		cout <<"Player Axe texture failure";
	}
	Clock clock;
	float dt;
	player.setTexture(playerTexture);
	player.setScale(Vector2f(8,8));
	player.setTextureRect(IntRect(10,10,30,30));
	Texture houseTextureMap;
	if(!houseTextureMap.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Wooden House.png")){
		cout << "Error house texture map\n";
	}

	float ss  = 20; 

	bool if_inside = false;
	bool center = true, left = false, right = false, up = false, down = false; 
	int left_anim = 0, right_anim = 0, up_anim = 0, down_anim = 0;
	View view(Vector2f(player.getPosition().x+10,player.getPosition().y-10), Vector2f(window.getSize()));
	bool can_move = true;

	//1=5
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
		if(event.type==Event::Closed){
			window.close();
		}
	}
	dt = clock.restart().asSeconds();  

		if (Keyboard::isKeyPressed(Keyboard::A) && can_move == true) {
			player.move(-500 * dt, 0);
			left = true;
		}

		else if (Keyboard::isKeyPressed(Keyboard::D) && can_move == true){
			player.move(500 * dt, 0);
			right = true;
		}

		else if (Keyboard::isKeyPressed(Keyboard::W) && can_move == true){
			player.move(0, -500 * dt);
			up = true;
		}

		else if (Keyboard::isKeyPressed(Keyboard::S) && can_move ==	 true){
			player.move(0, 500 * dt);
			down = true;
		}

		else{
			center = true, left = false, right = false, up = false, down = false;	
		}

		//kill me
		//p1
		if (left == true){
			player.setTextureRect(IntRect(10, 106,ss, 30));
			left_anim++;
		}
		//p2
		else if (right == true){
			player.setTextureRect(IntRect(10, 154, ss, 30));
			
			right_anim++;
		}
		//p3
		else if (up == true){
			player.setTextureRect(IntRect(10, 57, ss, 30));
			up_anim++;
		}
		//p4
		else if (down == true){
			player.setTextureRect(IntRect(10, 10, ss, 30));
			down_anim++;
		}
		//nom

		else if(Mouse::isButtonPressed(Mouse::Left)){
			player.setTexture(playerTextureAxe);
			player.setTextureRect(IntRect(10,251,ss,30));
		}

		else{
			center = true;
			player.setTextureRect(IntRect(10,10,ss,30));
			player.setTexture(playerTexture);
		}	
	//house nothing here for now

	view.setCenter(Vector2f(player.getPosition().x +10,player.getPosition().y - 10));
	window.clear(Color::Cyan);
	window.setView(view);
	//window.draw(path1);
	//window.draw(house);
	// draw obstacles there
	house house21(Vector2f(-460,-439)+house21.getScale(),window);
	house21.getInside();

	obstacle path1(17,Vector2f(0,590),window);
	obstacle path2(16,Vector2f(-165,590),window);
	obstacle path3(18,Vector2f(-125,590),window);

	obstacle path4(17,Vector2f(0,690),window);
	obstacle path5(16,Vector2f(-165,690),window);
	obstacle path6(18,Vector2f(-125,690),window);

	obstacle path7(17,Vector2f(0,790),window);
	obstacle path8(16,Vector2f(-165,790),window);
	obstacle path9(18,Vector2f(-125,790),window);

	obstacle path10(17,Vector2f(0,890),window);
	obstacle path11(4,Vector2f(0,990), window);
	obstacle path12(18,Vector2f(-125,890),window);

	window.draw(player);
	
	if(player.getGlobalBounds().intersects(house21.intersec())){
		if(player.getPosition().y >= 50){
			player.setPosition(player.getPosition().x,50);
		}

		else if(player.getPosition().y <= -200){
			player.setPosition(player.getPosition().x,-200);
		}

		else if(player.getPosition().x >= 20){
			player.setPosition(Vector2f(20,player.getPosition().y));
		}

		else if(player.getPosition().x <= -350){
			player.setPosition(Vector2f(-350,player.getPosition().y));
		}

		if(Keyboard::isKeyPressed(Keyboard::E)){
			player.setPosition(player.getPosition().x,680);
		}

	}

	window.display();
	}
	return 0;
}
