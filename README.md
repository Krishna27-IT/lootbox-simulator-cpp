# Lottery Simulator (C++)

A console-based gacha/lottery simulator built in C++.

## Features

- Weighted random reward system
- Single spin and 10-spin options
- Coin-based economy
- Inventory system
- Inventory statistics
- Drop rate analysis
- Save inventory to file
- Load inventory from file on startup
- Pity system (guaranteed Legendary after 20 non-Legendary pulls)
- Random number generation using Mersenne Twister (`mt19937`)

## Rewards

| Item | Rarity | Weight |
|--------|----------|----------|
| Basic AKM | Common | 40 |
| Green Shirt | Common | 30 |
| Blue Shoes | Rare | 15 |
| Epic Dance | Epic | 10 |
| Golden AKM | Legendary | 5 |

## Menu

```text
1. Spin
2. 10 Spin
3. Show Inventory
4. Inventory Statistics
5. Drop Rate Stats
6. Save File
7. Exit
```

## Concepts Practiced

- Structs
- Constructors
- Vectors
- References
- Functions
- Random Number Generation
- Weighted Probability
- Unordered Maps
- File Handling (ifstream/ofstream)
- Inventory Management
- Statistics Calculation
- Persistence (Save/Load)
- Pity System Logic

## Save File Format

Inventory is stored in:

```text
Won Items.txt
```

Example:

```text
Basic AKM,Common
Golden AKM,Legendary
Blue Shoes,Rare
```


## Future Improvements

- Inventory filtering by rarity
- Inventory sorting
- Multiple Legendary rewards
- Save/load pity counter
- Better file format
- Class-based design
- Banner system
- Reward selling system
- Shop system

