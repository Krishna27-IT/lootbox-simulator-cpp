#include "Reward.h"
using namespace std;

Reward::Reward(const string n,const string r, int w): name(n), rarity(r), weight(w){}

const string& Reward::getName() const
{
    return name;
}

const string& Reward::getRarity() const
{
    return rarity;
}

int Reward::getWeight() const
{
    return weight;
}