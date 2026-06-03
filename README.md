# Lottery Simulator (C++)

A console-based gacha/lottery simulator built in C++ to practice core programming concepts including structs, vectors, random number generation, file handling, hash maps, and game logic.

## Features

- Weighted random reward system
- Single Spin and 10x Spin
- Coin-based currency system
- Inventory management
- Inventory statistics tracking
- Drop rate analysis
- Save inventory to file
- Load inventory from file on startup
- Legendary pity system (guaranteed Legendary after 20 non-Legendary spins)
- Filter inventory by rarity
- Persistent inventory between program runs

## Rewards

| Item | Rarity | Weight |
|--------|----------|----------|
| Basic AKM | Common | 40 |
| Green Shirt | Common | 30 |
| Blue Shoes | Rare | 15 |
| Epic Dance | Epic | 10 |
| Golden AKM | Legendary | 5 |

## Menu

1. Spin
2. 10 Spin
3. Show Inventory
4. Inventory Statistics
5. Drop Rate Stats
6. Save File
7. Filter by Rarity
8. Exit

## Concepts Practiced

- Structs and constructors
- Vectors
- References (&)
- Const correctness
- Random number generation (mt19937)
- Weighted probability systems
- Functions and modular design
- File I/O (ifstream, ofstream)
- Hash maps (unordered_map)
- Data persistence
- Pity system implementation
- Menu-driven applications

## Save File Format

Inventory is stored in:

Won Items.txt

Example:

Basic AKM,Common
Golden AKM,Legendary
Blue Shoes,Rare

The file is automatically loaded when the program starts.

## Future Improvements

- Sell items for coins
- Sort inventory
- Multiple banners
- Inventory search
- Inventory quantity stacking
- Better save system
- Class-based (OOP) redesign
- Banner-specific pity counters


Project Goal: Practice C++ fundamentals through a progressively enhanced console application while learning real-world programming concepts such as randomness, persistence, and data management.