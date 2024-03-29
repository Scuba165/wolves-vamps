#include <iostream>
#include "../headers/tile.h"



    tile::tile() {
        this->is_character = 0;
        this->is_tree = 0;
        this->is_lake = 0;
        this->is_potion = 0;
        this->is_occupied = 0;
        this->is_ww = 0;
        this->is_vamp = 0;
    }

    // Potion picked-up or Entity Unalives
    void tile::make_grass() {
            this->is_potion = false;
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
        this->is_occupied = true;
    }

    void tile::make_werewolf() {
        this->is_ww = true;
        this->is_occupied = true;
    }

    void tile::make_vampire() {
        this->is_vamp = true;
        this->is_occupied = true;
    }

    void tile::free() {
        if(this->is_character) {
            this->is_character = false;
        }
        if(this->is_ww) {
            this->is_ww = false;
        }
        if(this->is_vamp) {
            this->is_vamp = false;
        }
        this->is_occupied = false;
    }
    
    bool tile::can_walk_on() {
        return !(this->is_occupied);
    }

    void tile::set_x(int inp) {
        this->x = inp;
    }

    void tile::set_y(int inp) {
        this->y = inp;
    }
    
    int tile::get_x() {
        return this->x;
    }

    int tile::get_y() {
        return this->y;
    }

    bool tile::is_pot() {
        return this->is_potion;
    }

    bool tile::is_werewolf() {
        return this->is_ww;
    }

    bool tile::is_vampire() {
        return this->is_vamp;
    }

    void tile::print() {
        if(this->is_character) {
            std::cout << "\033[;42m A \033[0m";
            return;
        }
        if(this->is_ww) {
            std::cout << "\033[;42m W \033[0m";
            return;
        }
        if(this->is_vamp) {
            std::cout << "\033[;42m V \033[0m";
            return;
        }
        if(this->is_tree) {
            std::cout << "\033[0;102;1m T \033[0m";
            return;
        }
        if(this->is_lake) {
            std::cout << "\033[;44m L \033[0m";
            return;  
        }
        if(this->is_potion) {
            std::cout << "\033[1;31;42m P \033[0m";
            return;
        }
        std::cout << "\033[;42m   \033[0m";
        return;
    }
