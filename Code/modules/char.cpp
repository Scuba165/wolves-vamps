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

void avatar::move(board board) {
    // MOVE LEFT
    if(GetAsyncKeyState('A') && (this->pos->get_x() > 0)) {
        this->pos->free();
        this->pos--;
        this->pos->make_character();
        return;
    }
    // MOVE RIGHT
    if(GetAsyncKeyState('D') && (this->pos->get_x() < board.get_width() - 1)) {
        this->pos->free();
        this->pos++;
        this->pos->make_character();
        return;
    }
    // MOVE UP
    if(GetAsyncKeyState('W') && (this->pos->get_y() > 0)) {
        this->pos->free();
        this->pos -= 11;
        this->pos->make_character();
        return;
    }
    // MOVE DOWN 
    if(GetAsyncKeyState('S') && (this->pos->get_y() < board.get_height() - 1)) {
        this->pos->free();
        this->pos += 11;
        this->pos->make_character();
        return;
    }
}
