// HEADER FOR CLASS TILE
#pragma once

class tile {
private:
    int x; 
    int y;
    bool is_tree;
    bool is_lake;
    bool is_potion;
    bool is_occupied;
    bool is_character;
    bool is_ww;
    bool is_vamp;

public:
    tile(); // Constructor, sets bools to 0.
    void print(); // Prints content.
    void set_x(int); // Sets X when board inits.
    void set_y(int); // Sets Y when board inits.
    int get_x(); // Returns X.
    int get_y(); // Returns Y.
    void make_grass(); // Potion to Grass.
    void make_tree(); // Generates tree.
    void make_lake(); // Generates lake.
    void make_potion(); // Generates potion.
    void make_occupied(); // Occupies tile for current turn.
    void make_character(); // Character is on tile.
    void make_werewolf(); // Werewolf is on tile.
    void make_vampire(); // Vampire is on tile.
    void free(); // Entity is no longer on tile.
    bool is_pot(); // Checks tile for potion
    bool is_vampire();
    bool is_werewolf();
    bool can_walk_on(); // Checks tile for occupancy.
};