#ifndef REWARD_H
#define REWARD_H

#include <string>

class Reward
{
private:
    std::string name;
    std::string rarity;
    int weight;

public:
    Reward(const std::string n, const std::string r, int w);

    const std::string& getName() const;
    const std::string& getRarity() const;
    int getWeight() const;
};

#endif