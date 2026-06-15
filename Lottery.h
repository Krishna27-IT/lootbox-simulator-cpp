#ifndef LOTTERYSYSTEM_H
#define LOTTERYSYSTEM_H

#include <vector>
#include <random>

#include "Reward.h"
#include "Player.h"
#include "Inventory.h"

class LotterySystem
{
private:
    Player player;
    Inventory inventory;

    std::vector<Reward> rewardPool;

    std::mt19937 gen;
    int totalWeight;

    int pityCounter;

    Reward performSpin();

    Reward pitySystem();

    void multipleSpin();
    void loadRewards();

public:
    LotterySystem();

    void run();
};

#endif