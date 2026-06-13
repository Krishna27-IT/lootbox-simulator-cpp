#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
private:
    int coin;
    std::string lastClaimedDate;

public:
    Player(int c, const std::string& d);

    int getCoin() const;
    void setCoin(int c);

    const std::string& getLastClaimedDate() const;

    std::string getCurrentDate() const;

    void claimDailyReward();

    void savePlayerData();
    void loadPlayerData();
};

#endif