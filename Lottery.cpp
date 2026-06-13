#include<iostream>
#include "Lottery.h"
#include<vector>

using namespace std;

LotterySystem::LotterySystem(): player(2000, ""), pityCounter(0), totalWeight(0){

    random_device rd;
    gen = mt19937(rd());

    player.loadPlayerData();
    inventory.loadInventory();

    rewardPool.emplace_back("Basic AKM","Common",40); 
    rewardPool.emplace_back("Green Shirt","Common",30); 
    rewardPool.emplace_back("Blue Shoes","Rare",15); 
    rewardPool.emplace_back("Epic Dance","Epic",10); 
    rewardPool.emplace_back("Golden AKM","Legendary",5);

    for(const Reward& r : rewardPool){
        totalWeight += r.getWeight();
    }
}

Reward LotterySystem::performSpin(){
    uniform_int_distribution<> dist(1, totalWeight);
    int randomNumber = dist(gen);

    int running_sum= 0;
    for(const Reward& r : rewardPool){
        running_sum += r.getWeight();
        if(randomNumber <= running_sum){
            return r;
        }
    }
    return Reward{"Nothing","Common",0};
}

void LotterySystem::multipleSpin(){
    for(int i=0;i<10;i++){
        Reward reward=pitySystem();
        cout<<"\nYOU WON!: "<<reward.getName()<<"\n";
        inventory.addItem(reward);
    }
}

Reward LotterySystem::pitySystem(){
    const int LEGENDARY_INDEX = 4;

    if(pityCounter >= 20){
        pityCounter=0; 
        return rewardPool[LEGENDARY_INDEX];
    }

    Reward r = performSpin();
    if(r.getRarity()==rewardPool[LEGENDARY_INDEX].getRarity()){
        pityCounter=0;
    }else{
        pityCounter++;
    }
    return r;
}

    void LotterySystem::run(){
        const int SPIN_COST = 100;
        const int TEN_SPIN_COST=900;

        int choice;

        while(true){
            cout<<"-------Lottery Simulator-------"<<endl;
            cout<<"\nAvailable Coins: "<<player.getCoin()<<endl;
            cout<<"1. Spin"<<endl;
            cout<<"2. 10 Spin"<<endl;
            cout<<"3. Show Inventory"<<endl;
            cout<<"4. Inventory Statistics"<<endl;
            cout<<"5. Drop Rate Stats: "<<endl;
            cout<<"6. Filter by Rarity"<<endl;
            cout<<"7. Sell Items"<<endl;
            cout<<"8. Sort Inventory"<<endl;
            cout<<"9. Claim Daily Reward"<<endl;
            cout<<"10. Exit!"<<endl;
            cout<<"Enter Your Choice: "<<endl;
            cin>>choice;

            switch (choice)
            {
            case 1:
                if(player.getCoin() >= SPIN_COST){
                    player.setCoin(player.getCoin() - SPIN_COST);
                    Reward reward = pitySystem();
                    cout<<"\nYOU WON!: "<<reward.getName()<<endl;
                    inventory.addItem(reward);
                    cout<<"Current Coin: "<<player.getCoin()<<endl;
                }else{
                    cout<<"\nInsufficient Coins!"<<endl;
                }
            
                inventory.saveInventory();
                player.savePlayerData();
                break;
        
            case 2:
                if(player.getCoin() >= TEN_SPIN_COST){
                    player.setCoin(player.getCoin() - TEN_SPIN_COST);
                    multipleSpin();
                    cout<<"\nCurrent Coin: "<<player.getCoin()<<endl;
                }else{
                    cout<<"\nInsufficient Coins!"<<endl;
                }
                inventory.saveInventory();
                player.savePlayerData();
                break;
        
            case 3:
                inventory.showInventory();
                break;

            case 4:
                inventory.showInventoryStats();
                break;

            case 5:
                inventory.showDropRates();
                break;

            case 6:
                inventory.filterByRarity();
                break;

            case 7:
                inventory.sellItem(player);
                inventory.saveInventory();
                player.savePlayerData();
                break;

            case 8:
                inventory.sortInventory();
                break;

            case 9:
                player.claimDailyReward();
                break;

            case 10:
                inventory.saveInventory();
                player.savePlayerData();
                return;
        
            default:
                cout<<"\nInvalid Input!"<<endl;
                break;
            }
        }

    }
    
