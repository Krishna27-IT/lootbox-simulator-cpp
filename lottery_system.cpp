#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<random>
#include<iomanip>
#include<fstream>
#include<algorithm>
using namespace std;

struct Reward{
    string name;
    string rarity;
    int weight;

    Reward(string n, string r, int w){
        name=n;
        rarity=r;
        weight=w;
    }
};

Reward performSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot){
    uniform_int_distribution<> dist(1, total_weight);
    int randomNumber = dist(gen);

    int running_sum= 0;
    for(const Reward& r : slot){
        running_sum += r.weight;
        if(randomNumber <= running_sum){
            return r;
        }
    }
    return Reward{"Nothing","Common",0};
}
Reward pitySystem(mt19937& gen,int total_weight,const vector<Reward>& slot,int& pityCounter);

void multipleSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot, vector<Reward>& inventory, int& pityCounter){
    for(int i=0;i<10;i++){
        Reward reward=pitySystem(gen,total_weight,slot,pityCounter);
        cout<<"\nYOU WON!: "<<reward.name<<"\n";
        inventory.push_back(reward);
    }
}

void showInventory(const vector<Reward>& inventory){
    if(inventory.empty()){
        cout << "\nInventory is empty!\n";
        return;
    }

    cout<<"\nWon Items: "<<endl;
    for(const Reward& i : inventory){
        cout<<i.name<<" ("<<i.rarity<<")\n";
    }
}

void showInventoryStats(const vector<Reward>& inventory){
    unordered_map<string, int> itemTracker;
    if(inventory.empty()){
        cout << "\nInventory is empty!\n";
        return;
    }

    for(const Reward& r : inventory){
        itemTracker[r.name]++;
    }

    cout<<endl;
    for(const auto& pair : itemTracker){
        cout<<pair.first<<" -> "<<pair.second<<endl;
    }
}

void showDropRates(const vector<Reward>& inventory){
    unordered_map<string, int> dropRate;
    if(inventory.empty()){
        cout << "\nInventory is empty!\n";
        return;
    }

    int total_items = inventory.size();
    for(const Reward& r : inventory){
        dropRate[r.name]++;
    }

    cout<<endl;
    for(const auto& count : dropRate){
        double percentage = (count.second * 100.0)/ total_items; 
        cout<<fixed<<setprecision(2);     
        cout<<count.first<<" -> "<<percentage<<"%\n";
    }
}

void saveInventory(const vector<Reward>& inventory){
    ofstream file("Won Items.txt");
    if(!file){
        cout<<"\nError Opening File!\n";
        return;
    }

    for(const Reward& r : inventory){
            file<<r.name<<","<<r.rarity<<"\n";
    }
}

void loadInventory(vector<Reward>& inventory){
    ifstream file("Won Items.txt");
    string line;
    if(!file){
        cout<<"\nNo save file found.\n";
        return;
    }

    while(getline(file, line)){
    size_t commaPos = line.find(',');
    string name = line.substr(0, commaPos);
    string rarity = line.substr(commaPos+1);
    inventory.emplace_back(name,rarity,0);
    }
}

Reward pitySystem(mt19937& gen, int total_weight, const vector<Reward>& slot, int& pityCounter){
    const int LEGENDARY_INDEX = 4;

    if(pityCounter >= 20){
        pityCounter=0; 
        return slot[LEGENDARY_INDEX];
    }

    Reward r = performSpin(gen, total_weight,slot);
    if(r.rarity==slot[LEGENDARY_INDEX].rarity){
        pityCounter=0;
    }else{
        pityCounter++;
    }
    return r;
}

void filterbyRarity(const vector<Reward>& inventory){
    if(inventory.empty()){
    cout << "\nInventory is empty!\n";
    return;
    }

    int choice;
    bool  found = false;
    cout<<"\nChoose Rarity: "<<endl;
    cout<<"1. Common"<<endl;
    cout<<"2. Rare"<<endl;
    cout<<"3. Epic"<<endl;
    cout<<"4. Legendary"<<endl;
    cin>>choice;

    string rarity;

    switch(choice){
        case 1:
            rarity = "Common";
            break;
        case 2:
            rarity = "Rare";
            break;
        case 3:
            rarity = "Epic";
            break;
        case 4:
            rarity = "Legendary";
            break;
        default:
            cout<<"\nInvalid Input!\n";
            return;
    }

    for(const Reward& r : inventory){
        if(r.rarity == rarity){
            cout<<r.name<<", "<<r.rarity<<endl;
            found = true;
        }
    }

    if(!found){
        cout<<"\nNo items found with the selected rarity!\n";
    }
}

int getSellPrice(const Reward& item){
    if(item.rarity== "Common") return 10;
    if(item.rarity== "Rare") return 50;
    if(item.rarity== "Epic") return 100;
    if(item.rarity== "Legendary") return 500;

    return 0;
}

void sellItem(vector<Reward>& inventory, int& coin){
    if(inventory.empty()){
    cout << "\nInventory is empty!\n";
    return;
    }

    cout<<endl;
    for(int i = 0; i < inventory.size(); i++){
        cout<<i<<". "<<inventory[i].name<<" ("<<inventory[i].rarity<<")\n";
    }

    int index;
    cout<<"\nEnter item index to sell: ";
    cin>>index;

    if(index < 0 || index >= inventory.size()){
        cout << "\nInvalid index!\n";
        return;
    }

    int price = getSellPrice(inventory[index]);
    coin += price;

    cout<<"\nSold "<< inventory[index].name<<" for "<<price<<" coins.\n";
    inventory.erase(inventory.begin()+index);
}

bool compareByName(const Reward& a, const Reward& b){
    return a.name < b.name;
}

int rarityRank(const string& rarity){
    if(rarity == "Legendary") return 1;
    if(rarity == "Epic") return 2;
    if(rarity == "Rare") return 3;
    if(rarity == "Common") return 4;
    return 5;
}

bool compareByRarity(const Reward& a, const Reward& b){
    return rarityRank(a.rarity) < rarityRank(b.rarity);
}

bool compareBySellItems(const Reward& a, const Reward& b){
    return getSellPrice(a) > getSellPrice(b);
}

void sortInventory(const vector<Reward>& inventory){
    if(inventory.empty()){
        cout << "\nInventory is empty!\n";
        return;
    }

    vector<Reward> sortedInventory = inventory;

    int choice;
    cout<<endl;
    cout<<"1. Sort By Name"<<endl;
    cout<<"2. Sort By Rarity"<<endl;
    cout<<"3. Sort By Sell Value"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            sort(sortedInventory.begin(), sortedInventory.end(), compareByName);
            for(const Reward& r : sortedInventory){
                cout<<r.name<<"\n";
            }
            break;
        
        case 2:
            sort(sortedInventory.begin(), sortedInventory.end(), compareByRarity);
            for(const Reward& r : sortedInventory){
                cout<<r.name<<" ("<<r.rarity<<")\n";
            }
            break;

        case 3:
            sort(sortedInventory.begin(), sortedInventory.end(), compareBySellItems);
            for(const Reward& r : sortedInventory){
                cout<<r.name<<" ("<<r.rarity<<")"<<" - "<<getSellPrice(r)<<"\n";
            }
            break;

        default:
            cout<<"\nInvalid Input!\n";
            return;
    }
}

int main(){
    int coin =2000;
    const int SPIN_COST = 100;
    const int TEN_SPIN_COST=900;

    vector<Reward> slot;
    slot.emplace_back("Basic AKM","Common",40); 
    slot.emplace_back("Green Shirt","Common",30); 
    slot.emplace_back("Blue Shoes","Rare",15); 
    slot.emplace_back("Epic Dance","Epic",10); 
    slot.emplace_back("Golden AKM","Legendary",5);

    random_device rd;
    mt19937 gen(rd());

    int total_weight=0;
   
    for(const Reward& r : slot){
        total_weight += r.weight;
    }

    vector<Reward> inventory;

    loadInventory(inventory);

    int choice;

    int pityCounter = 0;

    while(true){
        cout<<"-------Lottery Simulator-------"<<endl;
        cout<<"\nAvailable Coins: "<<coin<<endl;
        cout<<"1. Spin"<<endl;
        cout<<"2. 10 Spin"<<endl;
        cout<<"3. Show Inventory"<<endl;
        cout<<"4. Inventory Statistics"<<endl;
        cout<<"5. Drop Rate Stats: "<<endl;
        cout<<"6. Save File"<<endl;
        cout<<"7. Filter by Rarity"<<endl;
        cout<<"8. Sell Items"<<endl;
        cout<<"9. Sort Inventory"<<endl;
        cout<<"10. Exit!"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            if(coin >= SPIN_COST){
                coin -= SPIN_COST;
                Reward reward = pitySystem(gen,total_weight,slot,pityCounter);
                cout<<"\nYOU WON!: "<<reward.name<<endl;
                inventory.push_back(reward);
                cout<<"Current Coin: "<<coin<<endl;
            }else{
                cout<<"\nInsufficient Coins!"<<endl;
            }
            break;
        
        case 2:
            if(coin >= TEN_SPIN_COST){
                coin -= TEN_SPIN_COST;
                multipleSpin(gen,total_weight,slot,inventory,pityCounter);
                cout<<"\nCurrent Coin: "<<coin<<endl;
            }else{
                cout<<"\nInsufficient Coins!"<<endl;
            }
            break;
        
        case 3:
            showInventory(inventory);
            break;

        case 4:
            showInventoryStats(inventory);
            break;

        case 5:
            showDropRates(inventory);
            break;

        case 6: 
           saveInventory(inventory);
           cout << "\nInventory saved successfully!\n";
           break;

        case 7:
            filterbyRarity(inventory);
            break;

        case 8:
            sellItem(inventory, coin);
            break;

        case 9:
        sortInventory(inventory);
            break;

        case 10:
            return 0;
        
        default:
            cout<<"\nInvalid Input!"<<endl;
            break;
        }
    }

   return 0;
}