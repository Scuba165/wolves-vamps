// HEADER FILE FOR CHARACTER CLASSES. 
// tha vrw argotera public private klp
#include "tile.h"

class character {
    virtual void move() = 0;
    tile pos;
};

class werewolf : public character {
    const int health = 4; // random noumero gia tests
    int medkits; // 0-2 rand on spawn
    const int att; // 1-3 rand on spawn
    const int def; // 1-2 rand on spawn
};

class vampire : public character {
    const int health = 4; // random noumero gia tests
    int medkits; // 0-2 rand on spawn
    const int att; // 1-3 rand on spawn
    const int def; // 1-2 rand on spawn
};

class avatar : public character {
    bool supp_team; // 0 for Werewolves, 1 for Vampires
    int potion = 1; // Number of potions
};
