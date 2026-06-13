# Lottery System (C++)

A console-based lootbox / lottery simulator built in C++ to practice object-oriented programming, file handling, STL containers, random number generation, and multi-file project organization.

## Features

* Weighted random reward system
* Multiple reward rarities
* Single Spin
* 10x Spin
* Pity System (guaranteed Legendary after consecutive non-Legendary pulls)
* Inventory management
* Inventory statistics
* Drop rate analysis
* Filter inventory by rarity
* Sort inventory

  * By Name
  * By Rarity
  * By Sell Value
* Sell items for coins
* Daily reward system
* Save / Load player data
* Save / Load inventory data
* Menu-driven interface

---

## Reward Pool

| Item        | Rarity    | Weight |
| ----------- | --------- | ------ |
| Basic AKM   | Common    | 40     |
| Green Shirt | Common    | 30     |
| Blue Shoes  | Rare      | 15     |
| Epic Dance  | Epic      | 10     |
| Golden AKM  | Legendary | 5      |

---

## Game Mechanics

* Player starts with coins
* Single Spin costs 100 coins
* 10 Spin costs 900 coins
* Rewards are selected using weighted probability
* Items are stored in inventory
* Duplicate items are allowed
* Items can be sold for coins
* Progress is saved to local files

---

## Project Structure

```text
project/
│
├── main.cpp
│
├── Reward.h
├── Reward.cpp
│
├── Player.h
├── Player.cpp
│
├── Inventory.h
├── Inventory.cpp
│
├── Lottery.h
├── Lottery.cpp
│
├── Inventory.txt
└── Player Data.txt
```

---

## Concepts Practiced

### Object-Oriented Programming

* Classes
* Objects
* Encapsulation
* Constructors
* Member functions
* Access specifiers
* Multi-file project structure

### C++

* STL Vector
* STL Unordered Map
* References
* Const correctness
* Random number generation (`mt19937`)
* File handling (`ifstream`, `ofstream`)
* Sorting with custom comparators
* Menu-driven applications

### Software Design

* Separation of concerns
* Inventory management system
* Save/load persistence
* Weighted probability systems
* Basic game architecture

---

## Future Improvements

* JSON save system
* Player profiles
* Configurable reward pools
* Reward database
* Enum-based rarity system

---

## Build

Using g++:

```bash
g++ main.cpp Reward.cpp Player.cpp Inventory.cpp Lottery.cpp -o lottery_system
```

Run:

```bash
./lottery_system
```

---

## Learning Goal

This project was created as part of my C++ learning journey to move from procedural programming toward object-oriented design and larger multi-file applications.
