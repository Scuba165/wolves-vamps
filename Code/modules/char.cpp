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

void avatar::set_pos(int x, int y) {
    this->pos->free();
    this->pos = where->get_pos(x, y);
    std::cout << pos->get_x() << pos->get_y();
    this->pos->make_character();
}

void avatar::move() {
    //if(GetAsyncKeyState('W') & 0x8000) {
        this->set_pos(1, 1);
    //}
}
