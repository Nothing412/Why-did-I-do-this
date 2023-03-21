#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include"vars.hpp"
#include<SFML\System.hpp>
#include<vector>
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800,800),"Cat woodcutter", Style::Fullscreen);
	window.setFramerateLimit(60);
	Sprite path1;
	Texture sprite_map_1;
	if(!sprite_map_1.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
		cout << "Erorr sprite map 1\n";
	}
	Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
	path1.setTexture(sprite_map_1);
	path1.setScale(Vector2f(1000,1000));
	path1.setTextureRect(IntRect(3,0,22,22));
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
	Sprite path2;
	path2.setTexture(sprite_map_1);
	path2.setTextureRect(IntRect(10,10,30,30));

	Sprite house;
	house.setTexture(houseTextureMap);
	bool if_inside = false;
	bool center = true, left = false, right = false, up = false, down = false; 
	int left_anim = 0, right_anim = 0, up_anim = 0, down_anim = 0;
	View view(Vector2f(player.getPosition().x+10,player.getPosition().y-10), Vector2f(window.getSize())); 
	//1=5
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
		if(event.type==Event::Closed){
			window.close();
		}
	}
	dt = clock.restart().asSeconds();  

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			player.move(-500 * dt, 0);
			left = true;
		}

		else if (Keyboard::isKeyPressed(Keyboard::D)){
			player.move(500 * dt, 0);
			right = true;
		}

		else if (Keyboard::isKeyPressed(Keyboard::W)){
			player.move(0, -500 * dt);
			up = true;
		}

		else if (Keyboard::isKeyPressed(Keyboard::S)){
			player.move(0, 500 * dt);
			down = true;
		}

		else{
			center = true, left = false, right = false, up = false, down = false;	
		}

		//kill me
		//p1
		if (left == true){
			player.setTextureRect(IntRect(10, 106, 30, 30));
			left_anim++;
		}
		//p2
		else if (right == true){
			player.setTextureRect(IntRect(10, 154, 30, 30));
			
			right_anim++;
		}
		//p3
		else if (up == true){
			player.setTextureRect(IntRect(10, 57, 30, 30));
			up_anim++;
		}
		//p4
		else if (down == true){
			player.setTextureRect(IntRect(10, 10, 30, 30));
			down_anim++;
		}
		//nom

		else if(Mouse::isButtonPressed(Mouse::Left)){
			player.setTexture(playerTextureAxe);
			player.setTextureRect(IntRect(10,251,30,30));
		}

		else{
			center = true;
			player.setTextureRect(IntRect(10,10,30,30));
			player.setTexture(playerTexture);
		}
	//house nothing here for now

	view.setCenter(Vector2f(player.getPosition().x +10,player.getPosition().y - 10));
	window.clear();
	window.setView(view);
	//window.draw(path1);
	//window.draw(house);
	// draw obstacles there
	obstacle obstac(1,Vector2f(0,0),window);
	obstacle obstac2(2,Vector2f(300,0),window);
	obstacle obstac3(3,Vector2f(600,0),window);
	obstacle obstac4(4,Vector2f(1200,0),window);
	obstacle obstac5(5,Vector2f(1500,0),window);
	obstacle obstac6(6,Vector2f(1800,0),window);
	window.draw(player);
	window.display();
	}
	return 0;
}
