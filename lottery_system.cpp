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

Reward performSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot, vector<Reward>& inventory){
    uniform_int_distribution<> dist(1, total_weight);
    int randomNumber = dist(gen);

    int running_sum= 0;
    cout<<"\nYou Won! : "<<endl;
    for(const Reward& r : slot){
        running_sum += r.weight;
        if(randomNumber <= running_sum){
            cout<<r.name<<endl;
            inventory.push_back(r);
            return r;
        }
    }
    return Reward{"Nothing","Common",0};
}

void multipleSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot, vector<Reward>& inventory){
    for(int i=0;i<10;i++){
        performSpin(gen, total_weight, slot,inventory);
    }
}

void showInventory(const vector<Reward>& inventory){
    cout<<"\nWon Items: "<<endl;
    for(const Reward& i : inventory){
        cout<<i.name<<endl;
    }
}

int main(){
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
        cout<<"\n1. Spin"<<endl;
        cout<<"2. 10 Spin"<<endl;
        cout<<"3. Show Inventory"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            performSpin(gen,total_weight,slot,inventory);
            break;
        
        case 2:
            multipleSpin(gen,total_weight,slot,inventory);
            break;
        
        case 3:
            showInventory(inventory);
            break;

        case 4: 
            return 0;
        
        default:
            cout<<"\nInvalid Input!"<<endl;
            break;
        }
    }

   return 0;
}