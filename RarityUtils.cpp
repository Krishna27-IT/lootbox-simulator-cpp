#include "RarityUtils.h"

std::string rarityToString(Rarity rarity)
{
    switch(rarity)
    {
        case Rarity::Common:
            return "Common";

        case Rarity::Rare:
            return "Rare";

        case Rarity::Epic:
            return "Epic";

        case Rarity::Legendary:
            return "Legendary";
    }

    return "Unknown";
}

Rarity stringToRarity(const std::string& rarity)
{
    if(rarity == "Common")
        return Rarity::Common;

    if(rarity == "Rare")
        return Rarity::Rare;

    if(rarity == "Epic")
        return Rarity::Epic;

    if(rarity == "Legendary")
        return Rarity::Legendary;

    return Rarity::Common;
}