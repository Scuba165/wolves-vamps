#include <iostream>
#include <windows.h>
#include "../headers/char.h"


void character::move() {}

avatar::avatar(board board) {
    this->where = &board;
    std::cout << "Enter 0 to support Werewolves, 1 to support Vampires: ";
    std::cin >> this->supp_team;
    this->pos_init();
}


void avatar::pos_init() {
    int x = rand() % where->get_width();
    int y = rand() % where->get_height();
    while(where->at(x, y).can_walk_on() == false) {
            x = rand() % where->get_width();
            y = rand() % where->get_height();
    }
    this->pos = where->get_pos(x, y);
    this->pos->make_character();
} 

void avatar::move() {
    // MOVE LEFT
    if(GetAsyncKeyState('A')) {
        this->pos->free();
        this->pos--;
        this->pos->make_character();
    }
    // MOVE RIGHT
    if(GetAsyncKeyState('D')) {
        this->pos->free();
        this->pos++;
        this->pos->make_character();
    }
    // MOVE UP
    if(GetAsyncKeyState('W')) {
        this->pos->free();
        this->pos -= 11;
        this->pos->make_character();
    }
    // MOVE DOWN 
    if(GetAsyncKeyState('S')) {
        this->pos->free();
        this->pos += 11;
        this->pos->make_character();
    }
}
