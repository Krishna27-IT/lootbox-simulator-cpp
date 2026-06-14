# Lottery System (C++)

A console-based lootbox / lottery simulator built in C++ to practice object-oriented programming, file handling, weighted probability systems, and project organization.

## Features

* Weighted random reward system
* Multiple reward rarities
* Single spin
* 10x spin
* Inventory management
* Inventory statistics
* Drop rate tracking
* Item selling system
* Coin-based economy
* Daily reward system
* Pity system (guaranteed Legendary reward after a streak of bad luck)
* Inventory filtering by rarity
* Inventory sorting

  * By Name
  * By Rarity
  * By Sell Value
* Persistent save/load system
* Enum-based rarity system
* Multi-file project structure

## Rewards

| Item        | Rarity    | Weight |
| ----------- | --------- | ------ |
| Basic AKM   | Common    | 40     |
| Green Shirt | Common    | 30     |
| Blue Shoes  | Rare      | 15     |
| Epic Dance  | Epic      | 10     |
| Golden AKM  | Legendary | 5      |

## Game Mechanics

* Player starts with coins
* Single Spin costs 100 coins
* 10 Spin costs 900 coins
* Daily reward grants bonus coins once per day
* Rewards are selected using weighted probability
* Inventory and player data are saved between sessions
* Pity system guarantees a Legendary reward after 20 non-Legendary pulls

## Technologies Used

* C++
* STL Vector
* STL Unordered Map
* Enums
* Structuring with Header / Source Files
* File Handling
* Random Library (`<random>`)
* OOP Principles

## Concepts Practiced

* Object-Oriented Programming
* Class Design
* Encapsulation
* Multi-file Project Architecture
* Enum-based Design
* Weighted Random Selection
* File Persistence
* Inventory Management
* Sorting Algorithms
* Data Aggregation
* References and Const Correctness
* Git & GitHub Workflow

## Project Structure

```text
main.cpp
Lottery.cpp
Lottery.h
Inventory.cpp
Inventory.h
Player.cpp
Player.h
Reward.cpp
Reward.h
Rarity.h
RarityUtils.cpp
RarityUtils.h
```

## Future Improvements

* Reward Database
* JSON Save System

## Learning Goals

This project was built to strengthen:

* C++
* OOP Design
* File Handling
* Project Organization
* Software Refactoring
* Version Control
* Problem Solving
