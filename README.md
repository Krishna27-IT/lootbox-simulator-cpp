# Lottery System (C++)

A console-based lootbox / lottery simulator built in C++ featuring weighted rewards, inventory management, persistence, sorting, filtering, item selling, daily rewards, a pity system, and JSON-based save files.

The project was progressively expanded and refactored to practice software engineering fundamentals, object-oriented programming, file handling, data-driven design, and project organization.

---

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
* External reward database loaded from file
* Data-driven reward pool configuration

### Pity System

* Tracks consecutive non-Legendary pulls
* Guarantees a Legendary reward after 20 unsuccessful spins
* Automatically resets after obtaining a Legendary reward

### Inventory System

* Stores all obtained rewards
* Displays inventory contents
* Inventory statistics
* Drop-rate statistics
* Filter inventory by rarity
* Sort inventory:

  * By Name
  * By Rarity
  * By Sell Value

### Economy System

* Coin-based spinning system
* Item selling system
* Rarity-based sell values
* Coin balance tracking

### Daily Reward System

* Daily login reward
* Prevents duplicate claims on the same day
* Uses system date via `<ctime>`

### Persistence

* JSON-based player save system
* JSON-based inventory save system
* Save/load support between sessions
* Auto-save on important actions

---

## Reward Database

Rewards are loaded from an external database file.

Example:

```text
Basic AKM,Common,40
Green Shirt,Common,30
Blue Shoes,Rare,15
Epic Dance,Epic,10
Golden AKM,Legendary,5
```

New rewards can be added without modifying source code.

---

## Technologies Used

* C++
* STL Vector
* STL Unordered Map
* STL Algorithms (`sort`)
* Enumerations (`enum class`)
* File Handling (`fstream`)
* String Streams (`stringstream`)
* Random Library (`mt19937`)
* Time Library (`ctime`)
* JSON-style Data Serialization

---

## Concepts Practiced

### C++ Fundamentals

* Classes
* Constructors
* References
* Const Correctness
* Header / Source File Separation
* Multi-file Project Structure

### Data Structures

* Vector
* Unordered Map

### Software Engineering

* Object-Oriented Programming
* Encapsulation
* Refactoring
* Data-Driven Design
* Separation of Concerns
* Serialization & Deserialization
* Save System Design

### Algorithms

* Weighted Random Selection
* Sorting with Custom Comparators
* Inventory Aggregation
* Data Filtering

### Tools

* Git
* GitHub
* Command Line Compilation

---

## Project Structure

```text
lottery_system.cpp

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

player.json
inventory.json
```

---

## Example Save File

```json
{
    "coins": 2500,
    "lastClaimedDate": "2026-06-16"
}
```

---

## Learning Outcome

This project was built to strengthen practical C++ development skills through iterative development and continuous refactoring.

Key topics learned include:

* Object-Oriented Programming
* File Persistence
* JSON Serialization
* Data-Driven Design
* Multi-file Project Organization
* Enum-Based Design
* Inventory Management Systems
* Randomized Game Mechanics
* Git & GitHub Workflow
