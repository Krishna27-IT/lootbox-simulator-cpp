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
    Reward items1{"Basic AKM","Common",40};
    Reward items2{"Green Shirt","Common",30};
    Reward items3{"Blue Shoes","Rare",15};
    Reward items4{"Epic Dance","Epic",10};
    Reward items5{"Golden AKM","Legendary",5};

    vector<Reward> slot;
    slot.push_back(items1);
    slot.push_back(items2);
    slot.push_back(items3);
    slot.push_back(items4);
    slot.push_back(items5);

    random_device rd;
    mt19937 gen(rd());

    unordered_map<string, int> itemTracker;

    int total_weight=0;
   
    for(const Reward& r : slot){
        total_weight += r.weight;
    }

    for(int i=0;i<1000;i++){
        Reward wonItem = performSpin(gen, total_weight, slot);
        itemTracker[wonItem.name]++;
    }

    for(const auto& pair: itemTracker){
        cout<<"Item: "<< pair.first<<" | Count: "<<pair.second<<endl;
    }

   return 0;
}