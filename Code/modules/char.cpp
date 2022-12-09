#include <iostream>
#include <windows.h>
#include "../headers/char.h"


void character::move() {}

avatar::avatar(board inp) {
    this->where = &inp;
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

void avatar::move(board inp) {
    this->where = &inp;
    // MOVE LEFT
    if(GetAsyncKeyState('A') && (this->pos->get_x() > 0)) {
        this->pos->free();
        this->pos--;
        this->pos->make_character();
        return;
    }
    // MOVE RIGHT
    if(GetAsyncKeyState('D') && (this->pos->get_x() < where->get_width() - 1)) {
        this->pos->free();
        this->pos++;
        this->pos->make_character();
        return;
    }
    // MOVE UP
    if(GetAsyncKeyState('W') && (this->pos->get_y() > 0)) {
        // tile* new_pos = where->get_pos(this->pos->get_x(), this->pos->get_y() - 1);
        // if(new_pos->can_walk_on()) {
            this->pos->free();
            this->pos -= where->get_height() + 1;
            this->pos->make_character();
        //}
        return;
    }
    // MOVE DOWN 
    if(GetAsyncKeyState('S') && (this->pos->get_y() < where->get_height() - 1)) {
        this->pos->free();
        this->pos += where->get_height() + 1;
        this->pos->make_character();
        return;
    }
}
