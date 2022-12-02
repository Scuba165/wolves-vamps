#include <iostream>
#include "../headers/tile.h"
using namespace std;


    tile::tile() {
        this->is_character = 0;
        this->is_tree = 0;
        this->is_lake = 0;
        this->is_potion = 0;
        this->is_occupied = 0;
    }

    void tile::make_tree() {
        this->is_tree = true;
        this->is_occupied = true;
    }

    void tile::make_lake() {
        this->is_lake = true;
        this->is_occupied = true;
    }

    void tile::make_potion() {
        this->is_potion = true;
    }

    void tile::make_occupied() {
        this->is_occupied = true; 
    }

    void tile::make_character() {
        this->is_character = true;
    }

    void tile::free() {
        this->is_occupied = false;
    }
    
    bool tile::can_walk_on() {
        return (!this->is_occupied);
    }


    void tile::print() {
        if(this->is_tree) {
            cout << "\033[0;102;1m T \033[0m";
            return;
        }
        if(this->is_lake) {
            cout << "\033[;44m L \033[0m";
            return;  
        }
        if(this->is_potion) {
            cout << "\033[1;31;42m P \033[0m";
            return;
        }
        if(this->is_character) {
            cout << "\033[;42m A \033[0m";
            return;
        }
        cout << "\033[;42m   \033[0m";
        return;
    }
