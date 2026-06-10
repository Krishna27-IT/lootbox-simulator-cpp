# Lottery System (C++)

A console-based lootbox / lottery simulator built in C++ featuring weighted rewards, inventory management, persistence, sorting, filtering, item selling, a pity system, and daily login rewards.

## Features

### Reward System

* Weighted random reward generation using `mt19937`
* Multiple reward rarities:

  * Common
  * Rare
  * Epic
  * Legendary
* Single Spin
* 10x Multi Spin

### Pity System

* Tracks unsuccessful spins
* Guarantees a Legendary reward after 20 non-Legendary spins
* Automatically resets after obtaining a Legendary reward

### Inventory System

* Stores all obtained rewards
* Displays inventory contents
* Inventory statistics by item count
* Drop-rate statistics based on collected items
* Filter inventory by rarity
* Sort inventory:

  * By Name
  * By Rarity
  * By Sell Value

### Economy System

* Coin-based spinning system
* Item selling system
* Sell values determined by item rarity
* Coin balance tracking

### Daily Reward System

* Daily login reward (+200 coins)
* Prevents multiple claims on the same day
* Uses system date via `<ctime>`

### Persistence

* Save and load inventory from file
* Save and load player data:

  * Coins
  * Last claimed daily reward date
* Auto-save on exit

## Technologies Used

* C++
* STL Vector
* STL Unordered Map
* STL Algorithms (`sort`)
* Structs
* Functions
* File Handling (`fstream`)
* Random Library (`mt19937`)
* Time Library (`ctime`)

## Concepts Practiced

* Weighted probability systems
* Random number generation
* File I/O
* Data persistence
* Sorting with custom comparators
* Filtering data
* Inventory management
* Menu-driven applications
* Function decomposition
* STL containers and algorithms

## Future Improvements

* Object-Oriented Refactor (Classes)
* Multi-file Project Structure
* JSON Save Files
* Reward Streak System
* Achievement System
* Shop System
* Better UI Formatting
* Save All Game Data in a Unified Save System

## Learning Goal

This project was built to strengthen practical C++ programming skills through a progressively expanded console application involving random systems, persistence, inventory management, and game mechanics.
