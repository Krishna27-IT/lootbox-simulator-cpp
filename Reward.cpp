#include "Reward.h"
using namespace std;

Reward::Reward(const string& n,Rarity r, int w): name(n), rarity(r), weight(w){}

const string& Reward::getName() const
{
    return name;
}

Rarity Reward::getRarity() const
{
    return rarity;
}

int Reward::getWeight() const
{
    return weight;
}