# Lottery System (C++)

A console-based lottery/lootbox simulator built in C++ that uses weighted random probabilities to reward players with different items. The project demonstrates core C++ concepts including structs, vectors, unordered maps, random number generation, references, and menu-driven applications.

---

## Features

- Weighted random reward system
- Multiple item rarities
- Single Spin option
- 10 Spin option
- Coin-based economy
- Inventory system
- Inventory statistics
- Drop rate percentage tracking
- Menu-driven interface
- Random number generation using `mt19937`

---

## Rewards

| Item | Rarity | Weight |
|--------|----------|--------|
| Basic AKM | Common | 40 |
| Green Shirt | Common | 30 |
| Blue Shoes | Rare | 15 |
| Epic Dance | Epic | 10 |
| Golden AKM | Legendary | 5 |

### Reward Probabilities

| Item | Probability |
|--------|------------|
| Basic AKM | 40% |
| Green Shirt | 30% |
| Blue Shoes | 15% |
| Epic Dance | 10% |
| Golden AKM | 5% |

---

## Game Mechanics

- Player starts with **1000 Coins**
- Single Spin costs **100 Coins**
- 10 Spin costs **900 Coins**
- Rewards are selected using weighted probability
- Won items are stored in the inventory
- Inventory statistics track item counts
- Drop rate statistics show actual percentages obtained

---

## Menu

```text
1. Spin
2. 10 Spin
3. Show Inventory
4. Inventory Statistics
5. Drop Rate Stats
6. Exit