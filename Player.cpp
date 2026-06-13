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
    std::ofstream player_file("Player Data.txt");
    if(!player_file){
        std::cout<<"\nError Opening File!\n";
        return;
    }

    player_file<<coin<<"\n";
    player_file<<lastClaimedDate<<"\n";
}

void Player::loadPlayerData(){
    std::ifstream player_file("Player Data.txt");
    if(!player_file){
        std::cout<<"\nNo Save File Found!\n";
        return;
    }

    player_file >> coin >> lastClaimedDate;
}