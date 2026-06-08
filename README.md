# Lottery Simulator (C++)

A console-based gacha/lottery simulator built in C++ to practice STL, file handling, sorting, searching, random number generation, and inventory management.

## Features

### Lottery System
- Single Spin
- 10x Spin
- Weighted reward probabilities
- Random reward generation using `mt19937`

### Reward Rarities
- Common
- Rare
- Epic
- Legendary

### Pity System
- Tracks consecutive non-Legendary pulls
- Guarantees a Legendary reward after 20 unsuccessful spins
- Resets when a Legendary is obtained

### Inventory Management
- Store all obtained rewards
- Display inventory contents
- Show item rarity

### Inventory Statistics
- Count occurrences of each item
- Display inventory summary using `unordered_map`

### Drop Rate Statistics
- Calculates actual drop percentages from obtained rewards
- Displays percentages with 2 decimal precision

### Inventory Filtering
Filter inventory by:
- Common
- Rare
- Epic
- Legendary

### Item Selling System
Sell rewards directly from inventory.

Sell values:
| Rarity | Coins |
|----------|--------|
| Common | 10 |
| Rare | 50 |
| Epic | 100 |
| Legendary | 500 |

### Inventory Sorting
Sort inventory by:
- Name (Alphabetical)
- Rarity
- Sell Value

Sorting is performed on a copied inventory so the original inventory order remains unchanged.

### Save & Load System
- Save inventory to a text file
- Automatically load inventory when the program starts
- Inventory persistence across program sessions

## Concepts Practiced

### STL Containers
- `vector`
- `unordered_map`

### Algorithms
- `sort()`
- Custom comparator functions

### Random Number Generation
- `random_device`
- `mt19937`
- `uniform_int_distribution`

### File Handling
- `ifstream`
- `ofstream`

### Functions
- Parameter passing by reference
- Const correctness
- Modular function design

### Data Structures
- Structs
- Dynamic inventory management

## Project Structure

```text
Reward
 ├── name
 ├── rarity
 └── weight

Lottery System
 ├── Weighted Random Selection
 ├── Pity System
 └── Coin Economy

Inventory System
 ├── View Inventory
 ├── Statistics
 ├── Drop Rates
 ├── Filtering
 ├── Sorting
 ├── Selling
 ├── Save
 └── Load
```

## Sample Menu

```text
-------Lottery Simulator-------

Available Coins: 2000

1. Spin
2. 10 Spin
3. Show Inventory
4. Inventory Statistics
5. Drop Rate Stats
6. Save File
7. Filter by Rarity
8. Sell Items
9. Sort Inventory
10. Exit
```

## Learning Goals

This project was built to practice:

- C++ fundamentals
- STL containers
- Sorting with custom comparators
- Hash maps
- Randomized systems
- File persistence
- Inventory management systems
- Basic game backend logic

## Future Improvements

- Multiple save slots
- Shop system
- Buy coins feature
- Inventory search by name
- Reward IDs
- Duplicate item tracking
- Inventory pagination
- Better file format (CSV/JSON)
- Class-based architecture
- Database integration
