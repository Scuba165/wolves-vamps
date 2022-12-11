// HEADER FILE FOR CLASS CHARACTER AND SUBCLASSES 
#include "../headers/board.h"
#define MAX_HEALTH 6
#pragma once

class character {
    protected:
    virtual void move(board inp); // Moves the entity.
    board* where; // Pointer to board.
    tile* pos; // Pointer to current position.
    
};

class werewolf : public character {
    const int health = MAX_HEALTH; // Defined on top of .h file.
    int medkits; // 0-2 rand on spawn.
    const int att; // 1-3 rand on spawn.
    const int def; // 1-2 rand on spawn.
};

class vampire : public character {
    const int health = MAX_HEALTH; // Defined on top of .h file.
    int medkits; // 0-2 rand on spawn.
    const int att; // 1-3 rand on spawn.
    const int def; // 1-2 rand on spawn.
};

class avatar : public character {
    private:
    bool supp_team; // 0 for Werewolves, 1 for Vampires, player input.
    int pot_count = 1; // Number of potions

    public:
    avatar(board inp); // Constructor.
    void pos_init(); // Initializes position.
    void use_potion(); // Uses potion.
    void move(board inp); // Virtual function. 
};
