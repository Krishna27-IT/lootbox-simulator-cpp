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

int main(){
    vector<Reward> slot;
    slot.push_back({"Basic AKM","Common",40}); 
    slot.push_back({"Green Shirt","Common",30}); 
    slot.push_back({"Blue Shoes","Rare",15}); 
    slot.push_back({"Epic Dance","Epic",10}); 
    slot.push_back({"Golden AKM","Legendary",5});

    random_device rd;
    mt19937 gen(rd());

    unordered_map<string, int> itemTracker;

    int total_weight=0;
   
    for(const Reward& r : slot){
        total_weight += r.weight;
    }

    vector<Reward> inventory;

    for(int i=0;i<10;i++){
        Reward wonItem = performSpin(gen, total_weight, slot);
        inventory.push_back(wonItem);
        itemTracker[wonItem.name]++;
    }

    for(const auto& pair: itemTracker){
        cout<<"Item: "<< pair.first<<" | Count: "<<pair.second<<endl;
    }

    for(const Reward& i : inventory){
        cout<<"\nWon Items: "<<i.name<<endl;
    }

   return 0;
}