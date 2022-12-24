// HEADER FILE FOR CLASS CHARACTER AND SUBCLASSES 
#include "../headers/board.h"

#pragma once

class Vampire;

class character {
    protected:
    virtual void move(board inp); // Moves the entity.
    board* where; // Pointer to board.
    tile* pos; // Pointer to current position.
};

class avatar : public character {
    private:
    bool supp_team; // 0 for Werewolves, 1 for Vampires, player input.
    protected:
    int pot_count; // Number of potions

    public:
    avatar(board inp); // Constructor.
    void pos_init(); // Initializes position.
    void use_potion(); // Uses potion.
    void move(board inp); // Virtual function.
    int get_pots(); // Returns potion number. 
};

class Werewolf : public character {
public:
    int health;
    int damage;
    int defense;
    int medkits;

    Werewolf(board map);
    void move(board map);
    void pos_init();
    void scan(board map, std::vector<Vampire> vamps, std::vector<Werewolf> ww);
    tile* get_pos();
    void killed();
};

class Vampire : public character {
public:
    int health;
    int damage;
    int defense;
    int medkits;

    Vampire(board map);
    void move(board map);
    void pos_init();
    void scan(board map, std::vector<Vampire> vamps, std::vector<Werewolf> ww);
    tile* get_pos();
    void killed();
};
