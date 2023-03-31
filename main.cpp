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
			player.setTextureRect(IntRect(10,251,30,30));
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
	house house(Vector2f(-460 + 26,-439 + 70),window);
	
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

	obstacle path13(17,Vector2f(0,990),window);
	path13.setRotation(90);

	obstacle path14(16,Vector2f(-280,1151),window);
	path14.setRotation(270);	
	
	obstacle path15(16,Vector2f(-380,1151),window);
	path15.setRotation(270);
	
	obstacle path16(16,Vector2f(-480,1151),window);
	path16.setRotation(270);
	
	obstacle path17(16,Vector2f(-580,1151),window);
	path17.setRotation(270);	
	
	obstacle path18(16,Vector2f(-680,1151),window);
	path18.setRotation(270);	
	
	obstacle path19(16,Vector2f(-780,1151),window);
	path19.setRotation(270);	
	
	obstacle path20(16,Vector2f(-880,1151),window);
	path20.setRotation(270);	
	
	obstacle path21(16,Vector2f(-980,1151),window);
	path21.setRotation(270);

	
	//ssassert
	obstacle path22(17,Vector2f(-1080,1251),window);
	path14.setRotation(270);	
	
	obstacle path23(16,Vector2f(-380,1151),window);
	path15.setRotation(270);
	
	obstacle path24(16,Vector2f(-480,1151),window);
	path16.setRotation(270);
	
	obstacle path25(16,Vector2f(-580,1151),window);
	path17.setRotation(270);	
	
	obstacle path26(16,Vector2f(-680,1151),window);
	path18.setRotation(270);	
	
	obstacle path27(16,Vector2f(-780,1151),window);
	path19.setRotation(270);	
	
	obstacle path28(16,Vector2f(-880,1151),window);
	path20.setRotation(270);	
	
	obstacle path29(16,Vector2f(-980,1151),window);
	path21.setRotation(270);	
	
	//obstacle ☻

	path1.draw(window);
	path2.draw(window);
	path3.draw(window);
	path4.draw(window);
	path5.draw(window);
	path6.draw(window);
	path7.draw(window);
	path8.draw(window);
	path9.draw(window);
	path10.draw(window);
	path11.draw(window);
	path12.draw(window);
	path13.draw(window);
	path14.draw(window);
	path15.draw(window);
	path16.draw(window);
	path17.draw(window);
	path18.draw(window);
	path19.draw(window);
	path20.draw(window);
	path21.draw(window);
	path22.draw(window);

	

	window.draw(player);
	
	if(player.getGlobalBounds().intersects(house.intersec())){
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