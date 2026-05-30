#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<random>
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

void multipleSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot, vector<Reward>& inventory){
    for(int i=0;i<10;i++){
        Reward reward=performSpin(gen, total_weight, slot);
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
        cout<<i.name<<"\n";
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

    cout<<'\n'<<endl;
    for(const auto& pair : itemTracker){
        cout<<pair.first<<" -> "<<pair.second<<endl;
    }
}

int main(){
    int coin =1000;
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

    int choice;

    while(true){
        cout<<"-------Lottery Simulator-------"<<endl;
        cout<<"\nAvailable Coins: "<<coin<<endl;
        cout<<"1. Spin"<<endl;
        cout<<"2. 10 Spin"<<endl;
        cout<<"3. Show Inventory"<<endl;
        cout<<"4. Inventory Statistics"<<endl;
        cout<<"5. Exit!"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            if(coin >= SPIN_COST){
                coin -= SPIN_COST;
                Reward reward = performSpin(gen,total_weight,slot);
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
                multipleSpin(gen,total_weight,slot,inventory);
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
            return 0;
        
        default:
            cout<<"\nInvalid Input!"<<endl;
            break;
        }
    }

   return 0;
}