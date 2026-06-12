# Lottery System (C++)

A console-based lottery/lootbox simulator built in C++ to practice object-oriented programming, file handling, STL containers, random number generation, and software design principles.

## Features

### Lottery System

* Weighted random reward generation
* Multiple reward rarities
* Single Spin
* 10x Spin
* Mersenne Twister (`mt19937`) random engine

### Reward System

* Common, Rare, Epic, and Legendary rewards
* Weighted drop chances
* Inventory tracking

### Pity System

* Guaranteed Legendary reward after 20 non-Legendary spins
* Pity counter resets when a Legendary reward is obtained

### Inventory System

* Store won rewards
* View inventory
* Inventory statistics
* Filter inventory by rarity
* Sort inventory by:

  * Name
  * Rarity
  * Sell value

### Economy System

* Coin-based gameplay
* Single Spin cost: 100 coins
* 10x Spin cost: 900 coins
* Sell rewards for coins

### Daily Reward System

* Claim daily reward once per day
* Persistent date tracking
* Automatic save after claiming

### Save & Load System

* Inventory persistence using text files
* Player coin persistence
* Daily reward persistence
* Automatic loading on startup

## Object-Oriented Design

### Reward Class

Responsible for storing reward information.

Attributes:

* Name
* Rarity
* Weight

Methods:

* Getters for reward data

### Player Class

Responsible for player-related data and actions.

Attributes:

* Coins
* Last claimed daily reward date

Methods:

* Claim daily reward
* Save player data
* Load player data
* Coin management

### Inventory Class

Responsible for inventory management.

Methods:

* Add items
* Show inventory
* Show inventory statistics
* Show drop rates
* Filter by rarity
* Sort inventory
* Sell items
* Save inventory
* Load inventory

## Technologies Used

* C++
* STL Vector
* STL Unordered Map
* File Handling (`fstream`)
* Random Library (`<random>`)
* Time Library (`<ctime>`)
* Object-Oriented Programming

## Concepts Practiced

* Classes and Objects
* Constructors
* Encapsulation
* Getters
* File Persistence
* Random Number Generation
* Weighted Probability Systems
* Inventory Management
* Sorting Algorithms
* Searching and Filtering
* Menu-Driven Applications
* Pass-by-Reference
* Git & GitHub Workflow

## Future Improvements

* Split project into header and source files
* JSON-based save system
* LotterySystem controller class
* Better input validation
* Save pity counter
* Inventory search system
* Achievement system
* Improved console UI
* Unit testing

## Project Structure

```text
Lottery System
│
├── Reward Class
├── Player Class
├── Inventory Class
│
├── Lottery Logic
├── Pity System
├── Daily Reward System
├── Economy System
├── Inventory Management
│
├── Player Data.txt
└── Won Items.txt
```

## Learning Goals

This project was built to strengthen understanding of:

* Intermediate C++
* Object-Oriented Programming
* Data Structures
* File Handling
* Probability-Based Systems
* Software Refactoring
* Git Version Control
* Project Organization
