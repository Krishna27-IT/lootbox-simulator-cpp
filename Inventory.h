#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Reward.h"
#include "Player.h"

class Inventory{
private:
    std::vector<Reward> items;

public:
    void addItem(const Reward& reward);

    bool empty() const;
    int size() const;

    void showInventory() const;
    void showInventoryStats() const;
    void showDropRates() const;
    void filterByRarity() const;
    void sortInventory() const;

    void saveInventory() const;
    void loadInventory();

    void sellItem(Player& player);
};

#endif