# Lottery System (C++)

A console-based lootbox / lottery simulator built in C++ featuring weighted rewards, inventory management, persistence, sorting, filtering, item selling, a pity system, daily rewards, and a data-driven reward database.

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
* Reward database loaded from external file
* Data-driven reward pool configuration

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
* Sell values determined by rarity
* Coin balance tracking

### Daily Reward System

* Daily login reward (+200 coins)
* Prevents multiple claims on the same day
* Uses system date via `<ctime>`

### Persistence

* Save and load inventory from file
* Save and load player data
* Auto-save on important actions

## Technologies Used

* C++
* STL Vector
* STL Unordered Map
* STL Algorithms (`sort`)
* Enumerations (`enum class`)
* Structs & Classes
* File Handling (`fstream`)
* String Streams (`stringstream`)
* Random Library (`mt19937`)
* Time Library (`ctime`)

## Concepts Practiced

* Object-Oriented Programming
* Multi-file Project Structure
* Encapsulation
* Enum-based Design
* Weighted Probability Systems
* Random Number Generation
* File I/O
* Data Persistence
* CSV Parsing
* Data-Driven Design
* Sorting with Custom Comparators
* Filtering Data
* Inventory Management
* Menu-Driven Applications
* Function Decomposition
* STL Containers and Algorithms

## Project Structure

```text
main.cpp

Lottery.cpp
Lottery.h

Reward.cpp
Reward.h

Player.cpp
Player.h

Inventory.cpp
Inventory.h

Rarity.h
RarityUtils.cpp
RarityUtils.h

rewards.txt

Inventory.txt
Player Data.txt
```

## Reward Database

Rewards are loaded from an external text file:

```text
Basic AKM,Common,40
Green Shirt,Common,30
Blue Shoes,Rare,15
Epic Dance,Epic,10
Golden AKM,Legendary,5
```

This allows new rewards to be added without modifying source code.

## Learning Goal

This project was built to strengthen practical C++ software development skills through progressively adding game mechanics, persistence, refactoring, file parsing, and data-driven architecture while following a Git & GitHub workflow.
