#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>
#include<fstream>
#include<string>
#include<cstdlib>
#include<time.h>
#include"obstacles.h"
#include"house.h"
#include"tree.h"
#include"grass.h"
using namespace sf;
using namespace std;


int main(){
	RenderWindow window(VideoMode(800,800),"Cat woodcutter", Style::Fullscreen);
	window.setFramerateLimit(60);
	Texture sprite_map_1;
	if(!sprite_map_1.loadFromFile("../Sprout Lands - Sprites - Basic pack/Tilesets/ground tiles/new tiles/Grass hill tiles v.2.png")){
		cout << "Erorr sprite map 1\n";
	}
	Image icon;
	icon.loadFromFile("../icon.png");

	window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());	

	bool is_day = true;
	Sprite player;
	Texture playerTexture;	
	//bool is_day = true;
	bool is_hit=false;

	if(!playerTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Spritesheet.png")){
		cout << "Axe textureure failure";
	}
	


	Texture playerTextureAxe;
	if(!playerTextureAxe.loadFromFile("../Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions.png")){
		cout <<"Player Axe texture failure";
	}
	
	Texture  mouseTexture;
	Sprite mouseSprite;
	if(!mouseTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Objects/mouse.png")){
		cout << "sus\n";
	}
	mouseSprite.setTexture(mouseTexture);
	mouseSprite.setScale(2,2);

	Texture fenceFarmTexture;
	Sprite fenceFarm;
	if(!fenceFarmTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Tilesets/Tree Farm.png")){
		cout << "Error\n";
	}
	fenceFarm.setTexture(fenceFarmTexture);
	fenceFarm.setScale(Vector2f(20,20));
	fenceFarm.setPosition(Vector2f(-2178.5,450));
	
	int dat = 0; 
	Font font;
	Text dayText;
	if (!font.loadFromFile("../PublicPixel-z84yD.ttf")){
    	cout << "error loading font";
	}
	dayText.setFont(font);
	dayText.setCharacterSize(24);
	

	Clock clock;
	float dt;
	player.setTexture(playerTexture);
	player.setScale(Vector2f(8,8));
	player.setTextureRect(IntRect(10,10,30,30));
	Texture houseTextureMap;
	if(!houseTextureMap.loadFromFile("../Sprout Lands - Sprites - Basic pack/Tilesets/Wooden House.png")){
		cout << "Error house texture map\n";
	}

	float ss  = 21; 

	bool if_inside = false; 
	int left_anim = 0, right_anim = 0, up_anim = 0, down_anim = 0;
	View view(Vector2f(player.getPosition().x+10,player.getPosition().y-10), Vector2f(window.getSize()));
	bool can_move = true;
	Vector2i mousePos;
	
	ifstream playerY2;
	playerY2.open("../y.txt");
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
	playerX2.open("../x.txt");
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
			playerX.open("../x.txt");
			if(!playerX.is_open()){
				cout << "Error opening file\n";
			}
			playerX << player.getPosition().x;
			playerX.close();



			ofstream playerY;
			playerY.open("../y.txt");
			if(!playerY.is_open()){
				cout << "Error opening file\n";
			}
			playerY << player.getPosition().y;
			playerY.close();
				//
			}
		}

	//UPDATE


	//noiii
	//lkkll;
	const time_t now = time(nullptr) ; // get the current time point

    const tm calendar_time = *localtime( addressof(now) ) ;
	auto chewie = calendar_time.tm_min;
	
	int chip[] = {
		0,5,10,15,20,
		25,30,35,40,
		45,50,55,60
	};

	//13
	//1
	if(chewie == chip[0]){
		is_day = false;
	}
	//2
	else if(chewie == chip[1]){
		is_day = false;
	}
	//3
	else if(chewie == chip[2]){
		is_day = false;
	}
	//3
	else if(chewie == chip[3]){
		is_day = false;
	}

	else if(chewie == chip[4]){
		is_day = false;
	}

	else if(chewie == chip[5]){
		is_day = false;
	}

	else if(chewie == chip[6]){
		is_day = false;
	}

	else if(chewie == chip[7]){
		is_day = false;
	}

	else if(chewie == chip[8]){
		is_day = false;
	}

	else if(chewie == chip[9]){
		is_day = false;
	}

	else if(chewie == chip[10]){
		is_day = false;
	}

	else if(chewie == chip[11]){
		is_day = false;
	}

	else if(chewie == chip[12]){
		is_day = false;
	}

	else if(chewie == chip[13]){
		is_day = false;
	}
	else{
		is_day = true;
	}

	if(is_day == true){
		dayText.setFillColor(Color::Black);
	}

	else if(is_day == false){
		dayText.setFillColor(Color::White);
	}
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
			is_hit = true;
		}

		else{
			player.setTexture(playerTexture);
			player.setTextureRect(IntRect(10, 10, ss, 30));	
			is_hit = false;
		}

	view.setCenter(Vector2f(player.getPosition().x +10,player.getPosition().y - 10));
	if(is_day == true)
		window.clear(Color::Cyan);

	else if(is_day == false)
		window.clear(Color{2, 1, 28,255});
	window.setView(view);

	house house(Vector2f(-460 + 26,-439 + 70),window);
	
	obstacle path1(4);
	obstacle path2(6);
	obstacle path3(5);
	//2
	obstacle path4(4);
	obstacle path5(6);
	obstacle path6(5);
	//3
	obstacle path7(4);
	obstacle path8(6);
	obstacle path9(5);
	//4
	obstacle path10(4);
	obstacle path11(6);
	obstacle path12(5);

	obstacle path13(9);//path13.setRotation(90);
	obstacle path14(2);	
	obstacle path15(2);
	obstacle path16(2);
	obstacle path17(2);	
	obstacle path18(2);	
	obstacle path19(2);	
	obstacle path20(2);	

	obstacle path21(8);
	obstacle path22(8);	
	obstacle path23(8);
	obstacle path24(8);
	obstacle path25(8);	
	obstacle path26(8);	
	obstacle path27(8);	
	obstacle path28(8);
	obstacle path29(8);
	obstacle path30(8);
	obstacle path31(8);

	obstacle path32(6);
	obstacle path33(6);

	obstacle path34(5);
	obstacle path35(5);
	obstacle path36(5);
	obstacle path37(5);
	obstacle path38(5);
	obstacle path39(5);
	obstacle path40(5);

	obstacle path41(5);
	obstacle path42(5);
	obstacle path43(5);
	obstacle path44(5);

	Grass grass1(Vector2f(-1280,800),1);
	//polly
	Tree tree1(Vector2f(-1300,800));
	tree1.treeSetDeafult();



	path1.draw(window,Vector2f(-220,590));
	path2.draw(window,Vector2f(0,590));
	path3.draw(window,Vector2f(-100,590));
	//2
	path4.draw(window,Vector2f(-220,690));
	path5.draw(window,Vector2f(0,690));
	path6.draw(window,Vector2f(-100,690));
	//3
	path7.draw(window,Vector2f(-220,790));
	path8.draw(window,Vector2f(0,790));
	path9.draw(window,Vector2f(-100,790));
	//4
	path10.draw(window,Vector2f(-220,890));
	path11.draw(window,Vector2f(0,890));
	path12.draw(window,Vector2f(-100,890));


	path13.draw(window,Vector2f(0,1240));
	path14.draw(window,Vector2f(-350,1040));
	path15.draw(window,Vector2f(-450,1040));
	path16.draw(window,Vector2f(-550,1040));
	path17.draw(window,Vector2f(-650,1040));
	path18.draw(window,Vector2f(-750,1040));
	path19.draw(window,Vector2f(-850,1040));
	path20.draw(window,Vector2f(-950,1040));
	
	path21.draw(window,Vector2f(-1000,1240));
	path22.draw(window,Vector2f(-980,1240));
	path23.draw(window,Vector2f(-380,1240));
	path24.draw(window,Vector2f(-480,1240));
	path25.draw(window,Vector2f(-580,1240));
	path26.draw(window,Vector2f(-680,1240));
	path27.draw(window,Vector2f(-780,1240));
	path28.draw(window,Vector2f(-880,1240));
	path29.draw(window,Vector2f(-280,1240));
	path30.draw(window,Vector2f(-180,1240));	
	path31.draw(window,Vector2f(-157,1240));

	path32.draw(window,Vector2f(0,1050));
	path33.draw(window,Vector2f(0,1080));

	path34.draw(window,Vector2f(-350,1080));
	path35.draw(window,Vector2f(-450,1080));
	path36.draw(window,Vector2f(-550,1080));
	path37.draw(window,Vector2f(-650,1080));
	path38.draw(window,Vector2f(-750,1080));
	path39.draw(window,Vector2f(-850,1080));
	path40.draw(window,Vector2f(-950,1080));

	path41.draw(window,Vector2f(-100,1080));
	path42.draw(window,Vector2f(-200,1080));
	path43.draw(window,Vector2f(-100,1050));
	path44.draw(window,Vector2f(-200,1050));

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
	


	window.draw(fenceFarm);

	//draw grass
	grass1.draw(window);

	//draw tree

	/*if(player.getGlobalBounds().intersects(tree1.intersec())){
		if(is_hit == true){
			tree1.time++;
			

		}
	}*/

	/*if(tree1.canDraw == true){
		tree1.draw(window);
	}*/

	//tree1.draw(window);

	if(player.getGlobalBounds().intersects(tree1.intersec())){
		if(is_hit == true){
			tree1.time++;
			if(tree1.time >=116){
				tree1.treeMidbreak();
			}

			else if(tree1.time >=232){
				tree1.treeAlomstBreak();
			}

			else if (tree1.time >= 350){
				tree1.tree.clear();	
			}
		}
	}

	tree1.draw(window);

	window.draw(player);




	//window.draw(dayText);
	
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