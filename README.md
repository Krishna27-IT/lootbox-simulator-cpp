# Lottery System (C++)

A console-based lottery/lootbox simulator written in C++.

## Features

* Weighted random reward system
* Multiple reward rarities
* Single spin option
* 10x spin option
* Inventory system
* Inventory statistics
* Coin-based economy
* Menu-driven interface
* Random number generation using `mt19937`

## Rewards

| Item        | Rarity    | Weight |
| ----------- | --------- | ------ |
| Basic AKM   | Common    | 40     |
| Green Shirt | Common    | 30     |
| Blue Shoes  | Rare      | 15     |
| Epic Dance  | Epic      | 10     |
| Golden AKM  | Legendary | 5      |

## Game Mechanics

* Player starts with **1000 coins**
* Single Spin costs **100 coins**
* 10 Spin costs **900 coins**
* Rewards are selected using weighted probability
* Won items are stored in the player's inventory

## Menu

1. Spin
2. 10 Spin
3. Show Inventory
4. Inventory Statistics
5. Exit

## Technologies Used

* C++
* STL Vector
* STL Unordered Map
* Structs
* Constructors
* Functions
* References
* Random Library (`<random>`)

## Concepts Practiced

* Weighted random selection
* Inventory management
* Function design
* Passing by reference
* Constructors
* Data structures
  * Vector
  * Unordered Map
* Random number generation
* Menu-driven applications
* Git & GitHub workflow

## Future Improvements

* Drop rate percentage statistics
* Save/Load inventory
* Pity system
* Rarity-based inventory view
* Player profiles
* Class-based architecture
* Better console UI
