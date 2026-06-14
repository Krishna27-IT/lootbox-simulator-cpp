#include "Inventory.h"
#include "RarityUtils.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

void Inventory::addItem(const Reward& reward) {
    items.push_back(reward);

}

bool Inventory::empty() const {
    return items.empty();
}

int Inventory::size() const {
    return items.size();
}

void Inventory::showInventory() const {
    if (items.empty()) {
        cout << "\nInventory is empty!\n";
        return;
    }

    cout << "\nWon Items: " << endl;
    for (const Reward& i : items) {
        cout << i.getName() << " (" << rarityToString(i.getRarity()) << ")\n";
    }
}

void Inventory::showInventoryStats() const {
    unordered_map<string, int> itemTracker;
    if (items.empty()) {
        cout << "\nInventory is empty!\n";
        return;
    }

    for (const Reward& r : items) {
        itemTracker[r.getName()]++;
    }

    cout << endl;
    for (const auto& pair : itemTracker) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}

void Inventory::showDropRates() const {
    unordered_map<string, int> dropRate;
    if (items.empty()) {
        cout << "\nInventory is empty!\n";
        return;
    }

    int total_items = items.size();
    for (const Reward& r : items) {
        dropRate[r.getName()]++;
    }

    cout << endl;

    for (const auto& count : dropRate) {
        double percentage = (count.second * 100.0) / total_items;
        cout << fixed << setprecision(2);
        cout << count.first << " -> " << percentage << "%\n";
    }
}

void Inventory::filterByRarity() const {
    if (items.empty()) {
        cout << "\nInventory is empty!\n";
        return;
    }

    int choice;
    bool found = false;
    cout << "\nChoose Rarity: " << endl;
    cout << "1. Common" << endl;
    cout << "2. Rare" << endl;
    cout << "3. Epic" << endl;
    cout << "4. Legendary" << endl;
    cin >> choice;

    Rarity rarity;

    switch (choice) {
        case 1:
            rarity = Rarity::Common;
            break;
        case 2:
            rarity = Rarity::Rare;
            break;
        case 3:
            rarity = Rarity::Epic;
            break;
        case 4:
            rarity = Rarity::Legendary;
            break;
        default:
            cout << "\nInvalid Input!\n";
            return;
    }

    for (const Reward& r : items) {
        if (r.getRarity() == rarity) {
            cout << r.getName() << ", " << rarityToString(r.getRarity()) << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo items found with the selected rarity!\n";
    }
}

int rarityRank(Rarity rarity) {
    switch(rarity){
        case Rarity::Legendary:
            return 1;

        case Rarity::Epic:
            return 2;

        case Rarity::Rare:
            return 3;

        case Rarity::Common:
            return 4;
    }

    return 5;
}

int getSellPrice(const Reward& item) {
    if (item.getRarity() == Rarity::Common) return 10;
    if (item.getRarity() == Rarity::Rare) return 50;
    if (item.getRarity() == Rarity::Epic) return 100;
    if (item.getRarity() == Rarity::Legendary) return 500;

    return 0;
}

bool compareByName(const Reward& a, const Reward& b) {
    return a.getName() < b.getName();
}

bool compareByRarity(const Reward& a, const Reward& b) {
    return rarityRank(a.getRarity()) < rarityRank(b.getRarity());
}

bool compareBySellItems(const Reward& a, const Reward& b) {
    return getSellPrice(a) > getSellPrice(b);
}

void Inventory::sortInventory() const {
    if (items.empty()) {
        cout << "\nInventory is empty!\n";
        return;
    }

    vector<Reward> sortedInventory = items;

    int choice;
    cout << endl;
    cout << "1. Sort By Name" << endl;
    cout << "2. Sort By Rarity" << endl;
    cout << "3. Sort By Sell Value" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            sort(sortedInventory.begin(), sortedInventory.end(), compareByName);
            for (const Reward& r : sortedInventory) {
                cout << r.getName() << "\n";
            }
            break;

        case 2:
            sort(sortedInventory.begin(), sortedInventory.end(), compareByRarity);
            for (const Reward& r : sortedInventory) {
                cout << r.getName() << " (" << rarityToString(r.getRarity()) << ")\n";
            }
            break;

        case 3:
            sort(sortedInventory.begin(), sortedInventory.end(), compareBySellItems);
            for (const Reward& r : sortedInventory) {
                cout << r.getName() << " (" << rarityToString(r.getRarity()) << ")" << " - " << getSellPrice(r) << "\n";
            }
            break;

        default:
            cout << "\nInvalid Input!\n";
            return;
    }
}

void Inventory::saveInventory() const{
    ofstream file("Inventory.txt");
    if (!file) {
        cout << "\nError Opening File!\n";
        return;
    }

    for (const Reward& r : items) {
        file << r.getName() << "," << rarityToString(r.getRarity()) << "\n";
    }
}

void Inventory::loadInventory() {
    ifstream file("Inventory.txt");
    string line;
    if (!file) {
        cout << "\nNo save file found.\n";
        return;
    }

    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        string name = line.substr(0, commaPos);
        string rarityString = line.substr(commaPos + 1);

        items.emplace_back(name,stringToRarity(rarityString),0);
    }
}

void Inventory::sellItem(Player& player) {
    if (items.empty()) {
        cout << "\nInventory is empty!\n";
        return;
    }

    cout << "\nSelect an item to sell: " << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].getName() << " (" << rarityToString(items[i].getRarity()) << ") - " << getSellPrice(items[i]) << " coins\n";
    }

    int index;
    cin >> index;

    if (index < 1 || index > static_cast<int>(items.size())) {
        cout << "\nInvalid selection!\n";
        return;
    }

    int price = getSellPrice(items[index - 1]);
    player.setCoin(player.getCoin() + price);

    cout << "\nSold " << items[index - 1].getName() << " for " << price << " coins.\n";
    items.erase(items.begin() + index - 1);
}

