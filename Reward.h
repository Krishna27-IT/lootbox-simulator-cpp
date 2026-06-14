#ifndef REWARD_H
#define REWARD_H
#include "Rarity.h"
#include <string>

class Reward
{
private:
    std::string name;
    Rarity rarity;
    int weight;

public:
    Reward(const std::string& n, Rarity r, int w);

    const std::string& getName() const;
    Rarity getRarity() const;
    int getWeight() const;
};

#endif