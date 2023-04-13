#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>
#include<fstream>
#include<string>
#include"playerData.h"
#include"vars.hpp"
#include"house.h"
#include"fence.h"
#include"tree.h"
#include"grass.h"
using namespace sf;
using namespace std;

//if time is = 	day =< 300000 milliseconds
// 10  == 600000
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
	bool is_day = true;

	if(!playerTexture.loadFromFile("Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Spritesheet.png")){
		cout << "Axe textureure failure";
	}

	Texture playerTextureAxe;
	if(!playerTextureAxe.loadFromFile("Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions.png")){
		cout <<"Player Axe texture failure";
	}
	
	Texture  mouseTexture;
	Sprite mouseSprite;
	if(!mouseTexture.loadFromFile("Sprout Lands - Sprites - Basic pack/Objects/mouse.png")){
		cout << "sus\n";
	}
	mouseSprite.setTexture(mouseTexture);
	mouseSprite.setScale(2,2);

	Texture fenceFarmTexture;
	Sprite fenceFarm;
	if(!fenceFarmTexture.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Tree Farm.png")){
		cout << "Error\n";
	}
	fenceFarm.setTexture(fenceFarmTexture);
	fenceFarm.setScale(Vector2f(20,20));
	fenceFarm.setPosition(Vector2f(-2178.5,450));
	
	Clock clock;
	float dt;
	player.setTexture(playerTexture);
	player.setScale(Vector2f(8,8));
	player.setTextureRect(IntRect(10,10,30,30));
	Texture houseTextureMap;
	if(!houseTextureMap.loadFromFile("Sprout Lands - Sprites - Basic pack/Tilesets/Wooden House.png")){
		cout << "Error house texture map\n";
	}

	float ss  = 21; 

	bool if_inside = false; 
	int left_anim = 0, right_anim = 0, up_anim = 0, down_anim = 0;
	View view(Vector2f(player.getPosition().x+10,player.getPosition().y-10), Vector2f(window.getSize()));
	bool can_move = true;
	Vector2i mousePos;
	
	ifstream playerY2;
	playerY2.open("y.txt");
	if(!playerY2.is_open()){
		cout << "Error opening file\n";
    }
	string stringy;
	playerY2 >> stringy;
	playerY2.close();
	float y;
	y = stof(stringy);

	//oiiiii
	ifstream playerX2;
	playerX2.open("x.txt");
	if(!playerX2.is_open()){
		cout << "Error opening file\n";
    }
	string stringx;
	playerX2 >> stringx;
	playerX2.close();
	float x;
	x = stof(stringx);
	
	Vector2f playerPosition = Vector2f(x,y);
	player.setPosition(playerPosition);
	////////////////////////////////////////////////////////////////
	//here here here here here here here here here here here here //
	//here here here here here here here here here here here here //
	//here here here here here here here here here here here here //
	//here here here here here here here here here here here here //
	//here here here here here here here here here here here here //
	////////////////////////////////////////////////////////////////
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
				//
			ofstream playerX;
			playerX.open("x.txt");
			if(!playerX.is_open()){
				cout << "Error opening file\n";
			}
			playerX << player.getPosition().x;
			playerX.close();



			ofstream playerY;
			playerY.open("y.txt");
			if(!playerY.is_open()){
				cout << "Error opening file\n";
			}
			playerY << player.getPosition().y;
			playerY.close();
				//
			}
		}


	//noiii
	//lkkll;
	//poopo
		dt = clock.restart().asSeconds();  
		mousePos = Mouse::getPosition(window);

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
		}

		else{
			player.setTexture(playerTexture);
			player.setTextureRect(IntRect(10, 10, ss, 30));	
		}

	//nom

	//house nothing here for now


	view.setCenter(Vector2f(player.getPosition().x +10,player.getPosition().y - 10));
	window.clear(Color::Cyan);

	window.setView(view);
	//window.draw(path1);
	//window.draw(house);
	// draw obstacles there

	//cout << "x: " << player.getPosition().x << " y: " << player.getPosition().y << endl;

	

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
	obstacle path22(17,Vector2f(-980,1051),window);
	path22.setRotation(270);	
	
	obstacle path23(17,Vector2f(-380,1051),window);
	path23.setRotation(270);
	
	obstacle path24(17,Vector2f(-480,1051),window);
	path24.setRotation(270);
	
	obstacle path25(17,Vector2f(-580,1051),window);
	path25.setRotation(270);	
	
	obstacle path26(17,Vector2f(-680,1051),window);
	path26.setRotation(270);	
	
	obstacle path27(17,Vector2f(-780,1051),window);
	path27.setRotation(270);	
	
	obstacle path28(17,Vector2f(-880,1051),window);
	path28.setRotation(270);	
	
	obstacle path29(17,Vector2f(-280,1051),window);
	path29.setRotation(270);	

	Grass grass1(Vector2f(-1280,800),1);
	//polly
	Tree tree1(Vector2f(-1300,800));
	tree1.treeAlomstBreak(); 	


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
			player.setPosition(-884.039,player.getPosition().y);		
		}
	}

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
	path23.draw(window);
	path24.draw(window);
	path25.draw(window);
	path26.draw(window);
	path27.draw(window);
	path28.draw(window);
	path29.draw(window);

	


	window.draw(fenceFarm);

	//draw grass
	grass1.draw(window);

	//draw tree
	tree1.draw(window);

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