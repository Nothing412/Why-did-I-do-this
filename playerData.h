#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

struct PlayerData{
    float y;
    float x;
};

void savePlayerData(const PlayerData& data){
    ofstream file("playerData.txt");
    if(file.is_open()){
        file << data.x << endl;
        file << data.y << endl;
        file.close();
    }
};

void editPlayerData(const PlayerData& playerData){
    string line;
    string update_file_content;
    bool foundPLayer = false;
    
    ifstream file("playerData.txt");
    if(file.is_open()){
        while(getline(file,line)){
            if(line == to_string(playerData.x)){
                update_file_content += std::to_string(playerData.x) + "\n";
                foundPLayer = true;
            }
            else if(line == to_string(playerData.y)){
                update_file_content += std::to_string(playerData.y) + "\n";
                foundPLayer = true;
            }

            else{
                update_file_content += line + "\n";
            }
        }
    }
};