#include "Player.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

Player::Player(int c, const string& d) : coin(c), lastClaimedDate(d) {}

int Player::getCoin() const{
    return coin;
}

void Player::setCoin(int c){
    if(c >= 0){
        coin = c;
    }
}

const string& Player::getLastClaimedDate() const{
    return lastClaimedDate;
}

string Player::getCurrentDate() const{
    time_t now = time(nullptr);
    tm* currentTime = localtime(&now);

    char buffer[20];

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", currentTime);

    return string(buffer);
}

void Player::claimDailyReward(){
    const int DAILY_REWARD = 200;
    string today = getCurrentDate();
    if(lastClaimedDate != today){
        coin += DAILY_REWARD;
        lastClaimedDate = today;
        std::cout<<"\nDaily Reward Claimed!\n"<<std::endl;
    }else{
        std::cout<<"\nDaily reward already claimed today!\n"<<std::endl;
    }
    savePlayerData();
}

void Player::savePlayerData(){
    std::ofstream player_file("player.json");
    if(!player_file){
        std::cout<<"\nError Opening File!\n";
        return;
    }

    player_file << "{\n";
    player_file << "    \"coins\": " << coin << ",\n";
    player_file << "    \"lastClaimedDate\": \"" << lastClaimedDate << "\"\n";
    player_file << "}\n";
}

void Player::loadPlayerData(){
   string line;

    std::ifstream player_file("player.json");
    if(!player_file){
        std::cout<<"\nNo Save File Found!\n";
        return;
    }

    while(getline(player_file, line))
    {
        if(line.find("\"coins\":") != string::npos){
            size_t pos = line.find(":");
            if(pos != string::npos){
                coin = stoi(line.substr(pos + 1));
            }
    }
        if(line.find("\"lastClaimedDate\":") != string::npos){
            size_t pos = line.find(":");
            if(pos != string::npos){
                lastClaimedDate = line.substr(pos + 1);
                // Remove quotes
                lastClaimedDate = lastClaimedDate.substr(1, lastClaimedDate.length() - 2);
            }
        }
    }
}