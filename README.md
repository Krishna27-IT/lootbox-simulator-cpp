# Lottery Simulator (C++)

A console-based gacha/lottery simulator built in C++ to practice data structures, random number generation, file handling, inventory management, and game system design.

## Features

### Core Gacha System
- Weighted random reward drops
- Single Spin
- 10x Spin
- Coin-based currency system

### Inventory System
- Store won rewards
- Display inventory contents
- Inventory statistics
- Filter inventory by rarity
- Sell items for coins

### Statistics
- Item count tracking
- Drop rate percentage analysis
- Rarity-based filtering

### Persistence
- Save inventory to file
- Load inventory automatically on startup

### Pity System
- Guaranteed Legendary reward after 20 non-Legendary spins
- Counter resets after obtaining a Legendary reward

---

## Reward Pool

| Item | Rarity | Weight |
|--------|----------|----------|
| Basic AKM | Common | 40 |
| Green Shirt | Common | 30 |
| Blue Shoes | Rare | 15 |
| Epic Dance | Epic | 10 |
| Golden AKM | Legendary | 5 |

---

## Sell Values

| Rarity | Coins |
|----------|----------|
| Common | 10 |
| Rare | 50 |
| Epic | 100 |
| Legendary | 500 |

---

## Menu Options

```text
1. Spin
2. 10 Spin
3. Show Inventory
4. Inventory Statistics
5. Drop Rate Stats
6. Save File
7. Filter By Rarity
8. Sell Item
9. Exit