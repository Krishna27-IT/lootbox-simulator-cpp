#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<random>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<ctime>
using namespace std;

class Reward{
    private:
    string name;
    string rarity;
    int weight;
    
    public:
    Reward(string n, string r, int w) : name(n), rarity(r), weight(w) {}

    string getName() const{
        return name;
    }
    string getRarity() const{
        return rarity;
    }
    int getWeight() const{
        return weight;
    }
};

class Player{
    private:
    int coin;
    string lastClaimedDate;

    public:
    Player(int c, string d) : coin(c), lastClaimedDate(d) {}

    int getCoin() const{
        return coin;
    }

    void setCoin(int c){
        if(c >= 0){
            coin = c;
        }
    }

    const string& getLastClaimedDate() const{
        return lastClaimedDate;
    }

    string getCurrentDate() const{
        time_t now = time(nullptr);
        tm* currentTime = localtime(&now);

        char buffer[20];

        strftime(buffer, sizeof(buffer), "%Y-%m-%d", currentTime);

        return string(buffer);
    }

    void claimDailyReward(){
        string today = getCurrentDate();
        if(lastClaimedDate != today){
            coin += 200;
            lastClaimedDate = today;
            cout<<"\nDaily Reward Claimed!\n"<<endl;
        }else{
            cout<<"\nDaily reward already claimed today!\n"<<endl;
        }
        savePlayerData();
    }

    void savePlayerData(){
        ofstream player_file("Player Data.txt");
        if(!player_file){
         cout<<"\nError Opening File!\n";
            return;
        }

        player_file<<coin<<"\n";
        player_file<<lastClaimedDate<<"\n";
    }

    void loadPlayerData(){
        ifstream player_file("Player Data.txt");
        if(!player_file){
            cout<<"\nNo Save File Found!\n";
            return;
        }

        player_file >> coin >> lastClaimedDate;
    }
};

int getSellPrice(const Reward& item);

bool compareByName(const Reward& a, const Reward& b);

bool compareByRarity(const Reward& a, const Reward& b);

bool compareBySellItems(const Reward& a, const Reward& b);


class Inventory{
    private:
    vector<Reward> items;

    public:

    void addItem(const Reward& reward){
        items.push_back(reward);
    }
    bool empty() const{
        return items.empty();
    }
    int size() const{
        return items.size();
    }

    void showInventory() const{
        if(items.empty()){
            cout << "\nInventory is empty!\n";
            return;
        }

        cout<<"\nWon Items: "<<endl;
        for(const Reward& i : items){
         cout<<i.getName()<<" ("<<i.getRarity()<<")\n";
        }
    }

    void showInventoryStats() const{
        unordered_map<string, int> itemTracker;
        if(items.empty()){
            cout << "\nInventory is empty!\n";
            return;
        }

        for(const Reward& r : items){
            itemTracker[r.getName()]++;
        }

        cout<<endl;
        for(const auto& pair : itemTracker){
            cout<<pair.first<<" -> "<<pair.second<<endl;
        }
    }

    void showDropRates() const{
        unordered_map<string, int> dropRate;
        if(items.empty()){
            cout << "\nInventory is empty!\n";
            return;
        }

        int total_items = items.size();
        for(const Reward& r : items){
            dropRate[r.getName()]++;
        }

        cout<<endl;
        for(const auto& count : dropRate){
            double percentage = (count.second * 100.0)/ total_items; 
            cout<<fixed<<setprecision(2);     
            cout<<count.first<<" -> "<<percentage<<"%\n";
        }
    }

    void filterByRarity() const{
        if(items.empty()){
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

        for(const Reward& r : items){
            if(r.getRarity() == rarity){
                cout<<r.getName()<<", "<<r.getRarity()<<endl;
                found = true;
            }
        }

        if(!found){
            cout<<"\nNo items found with the selected rarity!\n";
        }
    }

    void sortInventory() const{
        if(items.empty()){
            cout << "\nInventory is empty!\n";
            return;
        }

        vector<Reward> sortedInventory = items;

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
                    cout<<r.getName()<<"\n";
                }
                break;
        
            case 2:
                sort(sortedInventory.begin(), sortedInventory.end(), compareByRarity);
                for(const Reward& r : sortedInventory){
                    cout<<r.getName()<<" ("<<r.getRarity()<<")\n";
                }
                break;

            case 3:
                sort(sortedInventory.begin(), sortedInventory.end(), compareBySellItems);
                for(const Reward& r : sortedInventory){
                    cout<<r.getName()<<" ("<<r.getRarity()<<")"<<" - "<<getSellPrice(r)<<"\n";
                }
                break;

            default:
                cout<<"\nInvalid Input!\n";
                return;
        }
    }

    void saveInventory(){
        ofstream file("Won Items.txt");
        if(!file){
            cout<<"\nError Opening File!\n";
            return;
        }

        for(const Reward& r : items){
            file<<r.getName()<<","<<r.getRarity()<<"\n";
        }
    }

    void loadInventory(){
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
        items.emplace_back(name,rarity,0);
        }
    }

    void sellItem(Player& player){
        if(items.empty()){
            cout << "\nInventory is empty!\n";
            return;
        }

        cout<<endl;
        for(int i = 0; i < items.size(); i++){
            cout<<i+1<<". "<<items[i].getName()<<" ("<<items[i].getRarity()<<")\n";
        }

        int index;
        cout<<"\nEnter item index to sell: ";
        cin>>index;

        if(index < 1 || index > items.size()){
            cout << "\nInvalid index!\n";
            return;
        }

        int price = getSellPrice(items[index-1]);
        player.setCoin(player.getCoin() + price);

        cout<<"\nSold "<< items[index-1].getName()<<" for "<<price<<" coins.\n";
        items.erase(items.begin()+index-1);
    }
};

Reward performSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot){
    uniform_int_distribution<> dist(1, total_weight);
    int randomNumber = dist(gen);

    int running_sum= 0;
    for(const Reward& r : slot){
        running_sum += r.getWeight();
        if(randomNumber <= running_sum){
            return r;
        }
    }
    return Reward{"Nothing","Common",0};
}
Reward pitySystem(mt19937& gen,int total_weight,const vector<Reward>& slot,int& pityCounter);

void multipleSpin(mt19937& gen ,int total_weight,const vector<Reward>& slot, Inventory& inventory, int& pityCounter){
    for(int i=0;i<10;i++){
        Reward reward=pitySystem(gen,total_weight,slot,pityCounter);
        cout<<"\nYOU WON!: "<<reward.getName()<<"\n";
        inventory.addItem(reward);
    }
}

Reward pitySystem(mt19937& gen, int total_weight, const vector<Reward>& slot, int& pityCounter){
    const int LEGENDARY_INDEX = 4;

    if(pityCounter >= 20){
        pityCounter=0; 
        return slot[LEGENDARY_INDEX];
    }

    Reward r = performSpin(gen, total_weight,slot);
    if(r.getRarity()==slot[LEGENDARY_INDEX].getRarity()){
        pityCounter=0;
    }else{
        pityCounter++;
    }
    return r;
}

int getSellPrice(const Reward& item){
    if(item.getRarity()== "Common") return 10;
    if(item.getRarity()== "Rare") return 50;
    if(item.getRarity()== "Epic") return 100;
    if(item.getRarity()== "Legendary") return 500;

    return 0;
}

bool compareByName(const Reward& a, const Reward& b){
    return a.getName() < b.getName();
}

int rarityRank(const string& rarity){
    if(rarity == "Legendary") return 1;
    if(rarity == "Epic") return 2;
    if(rarity == "Rare") return 3;
    if(rarity == "Common") return 4;
    return 5;
}

bool compareByRarity(const Reward& a, const Reward& b){
    return rarityRank(a.getRarity()) < rarityRank(b.getRarity());
}

bool compareBySellItems(const Reward& a, const Reward& b){
    return getSellPrice(a) > getSellPrice(b);
}

int main(){
    Player player(2000, "");
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
        total_weight += r.getWeight();
    }

    Inventory inventory;

    inventory.loadInventory();
    player.loadPlayerData();

    int choice;

    int pityCounter = 0;

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
                Reward reward = pitySystem(gen,total_weight,slot,pityCounter);
                cout<<"\nYOU WON!: "<<reward.getName()<<endl;
                inventory.addItem(reward);
                cout<<"Current Coin: "<<player.getCoin()<<endl;
            }else{
                cout<<"\nInsufficient Coins!"<<endl;
            }
            player.savePlayerData();
            break;
        
        case 2:
            if(player.getCoin() >= TEN_SPIN_COST){
                player.setCoin(player.getCoin() - TEN_SPIN_COST);
                multipleSpin(gen,total_weight,slot,inventory,pityCounter);
                cout<<"\nCurrent Coin: "<<player.getCoin()<<endl;
            }else{
                cout<<"\nInsufficient Coins!"<<endl;
            }
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
            return 0;
        
        default:
            cout<<"\nInvalid Input!"<<endl;
            break;
        }
    }

    inventory.saveInventory();
    player.savePlayerData();

   return 0;
}