// TILE HEADER FILE
#pragma once

class tile {
private:
    bool is_tree;
    bool is_lake;
    bool is_potion;
    bool is_occupied;
    bool is_character;
public:
    tile();
    void print();
    void make_tree();
    void make_lake();
    void make_potion();
    void make_occupied();
    void make_character();
    void free();
    bool can_walk_on();
};