#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>
#include<fstream>
#include<string>
#include<cstdlib>
#include<time.h>
#include<bits/stdc++.h>
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

	Tree tree1(Vector2f(-1300,800));
	Tree tree2(Vector2f(-1500,800));
	Tree tree3(Vector2f(-1700,800));
	Tree tree4(Vector2f(-1900,800));

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
	Grass grass2(Vector2f(-1380,800),1);
	Grass grass3(Vector2f(-1480,800),1);
	Grass grass4(Vector2f(-1580,800),1);
	Grass grass5(Vector2f(-1680,800),1);
	Grass grass6(Vector2f(-1780,800),1);
	Grass grass7(Vector2f(-1880,800),1);
	Grass grass8(Vector2f(-1980,800),1);
	Grass grass9(Vector2f(-1980,800),1);
	///22
	Grass grass10(Vector2f(-1280,900),2);
	Grass grass11(Vector2f(-1380,900),1);
	Grass grass12(Vector2f(-1480,900),1);
	Grass grass13(Vector2f(-1580,900),1);
	Grass grass14(Vector2f(-1680,900),1);
	Grass grass15(Vector2f(-1780,900),1);
	Grass grass16(Vector2f(-1880,900),1);
	Grass grass17(Vector2f(-1980,900),1);
	//,,.,
	Grass grass18(Vector2f(-1280,1000),1);
	Grass grass19(Vector2f(-1380,1000),1);
	Grass grass20(Vector2f(-1480,1000),1);
	Grass grass21(Vector2f(-1580,1000),1);
	Grass grass22(Vector2f(-1680,1000),1);
	Grass grass23(Vector2f(-1780,1000),1);
	Grass grass24(Vector2f(-1880,1000),1);
	Grass grass25(Vector2f(-1980,1000),1);
	//sax
	Grass grass26(Vector2f(-1280,1100),1);
	Grass grass27(Vector2f(-1380,1100),1);
	Grass grass28(Vector2f(-1480,1100),1);
	Grass grass29(Vector2f(-1580,1100),1);
	Grass grass30(Vector2f(-1680,1100),1);
	Grass grass31(Vector2f(-1780,1100),1);
	Grass grass32(Vector2f(-1880,1100),1);
	Grass grass33(Vector2f(-1980,1100),1);
	//polly
	Grass grass34(Vector2f(-1280,1200),1);
	Grass grass35(Vector2f(-1380,1200),1);
	Grass grass36(Vector2f(-1480,1200),1);
	Grass grass37(Vector2f(-1580,1200),1);
	Grass grass38(Vector2f(-1680,1200),1);
	Grass grass39(Vector2f(-1780,1200),1);
	Grass grass40(Vector2f(-1880,1200),1);
	Grass grass41(Vector2f(-1980,1200),1);

	Grass grass42(Vector2f(-1280,1300),1);
	Grass grass43(Vector2f(-1380,1300),1);
	Grass grass44(Vector2f(-1480,1300),1);
	Grass grass45(Vector2f(-1580,1300),1);
	Grass grass46(Vector2f(-1680,1300),1);
	Grass grass47(Vector2f(-1780,1300),1);
	Grass grass48(Vector2f(-1880,1300),1);
	Grass grass49(Vector2f(-1980,1300),1);

	Grass grass50(Vector2f(-1280,1400),1);
	Grass grass51(Vector2f(-1380,1400),1);
	Grass grass52(Vector2f(-1480,1400),1);
	Grass grass53(Vector2f(-1580,1400),1);
	Grass grass54(Vector2f(-1680,1400),1);
	Grass grass55(Vector2f(-1780,1400),1);
	Grass grass56(Vector2f(-1880,1400),1);
	Grass grass57(Vector2f(-1980,1400),1);


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
	

	if(player.getGlobalBounds().intersects(tree1.intersec())){
		tree1.time++;
		if(is_hit){
			tree1.time++;
			if(tree1.time <= 400){
				tree1.treeMidbreak();
				tree1.deleteKindOf();
			}
		}

		if(tree1.time == 0){
			tree1.treeSetDeafult();
		}
	}

	//tree2
	if(player.getGlobalBounds().intersects(tree2.intersec())){
		tree2.time++;
		if(is_hit){
			tree2.time++;
			if(tree2.time <= 400){
				tree2.treeMidbreak();
				tree2.deleteKindOf();
			}
		}

		if(tree2.time == 0){
			tree2.treeSetDeafult();
		}
	}

	//tree3
	if(player.getGlobalBounds().intersects(tree3.intersec())){
		tree3.time++;
		if(is_hit){
			tree3.time++;
			if(tree3.time <= 400){
				tree3.treeMidbreak();
				tree3.deleteKindOf();
			}
		}

		if(tree3.time == 0){
			tree3.treeSetDeafult();
		}
	}

	//tree4
	if(player.getGlobalBounds().intersects(tree4.intersec())){
		tree4.time++;
		if(is_hit){
			tree4.time++;
			if(tree4.time <= 400){
				tree4.treeMidbreak();
				tree4.deleteKindOf();
			}
		}

		if(tree4.time == 0){
			tree4.treeSetDeafult();
		}
	}

	


	//draw grass
	grass1.draw(window);
	grass2.draw(window);
	grass3.draw(window);
	grass4.draw(window);
	grass5.draw(window);
	grass6.draw(window);
	grass7.draw(window);
	grass8.draw(window);
	grass9.draw(window);
	grass10.draw(window);
	grass11.draw(window);
	grass12.draw(window);
	grass13.draw(window);
	grass14.draw(window);
	grass15.draw(window);
	grass16.draw(window);
	grass17.draw(window);
	grass18.draw(window);
	grass19.draw(window);
	grass20.draw(window);
	grass21.draw(window);
	grass22.draw(window);
	grass23.draw(window);
	grass24.draw(window);
	grass25.draw(window);

	grass26.draw(window);
	grass27.draw(window);
	grass28.draw(window);
	grass29.draw(window);
	grass30.draw(window);
	grass31.draw(window);
	grass32.draw(window);
	grass33.draw(window);

	//S
	grass26.draw(window);
	grass27.draw(window);
	grass28.draw(window);
	grass29.draw(window);
	grass30.draw(window);
	grass31.draw(window);
	grass32.draw(window);
	grass33.draw(window);
	//ss/sqasa
	grass32.draw(window);
	grass33.draw(window);
	grass34.draw(window);
	grass35.draw(window);
	grass36.draw(window);
	grass37.draw(window);
	grass38.draw(window);
	grass39.draw(window);

	grass40.draw(window);
	grass41.draw(window);
	grass42.draw(window);
	grass43.draw(window);
	grass44.draw(window);
	grass45.draw(window);
	grass46.draw(window);
	grass47.draw(window);
	grass48.draw(window);
	grass49.draw(window);

	grass50.draw(window);
	grass51.draw(window);
	grass52.draw(window);
	grass53.draw(window);
	grass54.draw(window);
	grass55.draw(window);
	grass56.draw(window);
	grass57.draw(window);
	
	//draw tree


	//tree1.draw(window);


	tree1.draw(window);
	tree2.draw(window);
	tree3.draw(window);
	tree4.draw(window);

	window.draw(fenceFarm);

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