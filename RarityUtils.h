#ifndef RARITYUTILS_H
#define RARITYUTILS_H

#include <string>
#include "Rarity.h"

std::string rarityToString(Rarity rarity);
Rarity stringToRarity(const std::string& rarity);

#endif