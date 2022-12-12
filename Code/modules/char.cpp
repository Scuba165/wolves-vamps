#include <iostream>
#include <windows.h>
#include "../headers/char.h"


void character::move(board inp) {}

//idea: constructor gia yperklash
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
    int curr_x = this->pos->get_x();
    int curr_y = this->pos->get_y();
    // MOVE LEFT
    if((GetAsyncKeyState('A') & 0x8000) && (curr_x > 0)) {
        if(where->get_pos(curr_x - 1, curr_y)->can_walk_on()) {
            this->pos->free();
            this->pos = where->get_pos(curr_x - 1, curr_y);
            this->pos->make_character();
        }
        if (this->pos->is_pot()) {
            this->pos->make_grass();
            this->pot_count++;
        }
        return;
    }
    // MOVE RIGHT
    if((GetAsyncKeyState('D') & 0x8000) && (curr_x < where->get_width() - 1)) {
        if(where->get_pos(curr_x + 1, curr_y)->can_walk_on()) {
            this->pos->free();
            this->pos = where->get_pos(curr_x + 1, curr_y);
            this->pos->make_character();
        }
        if (this->pos->is_pot()) {
            this->pos->make_grass();
            this->pot_count++;
        }
        return;
    }
    // MOVE UP
    if((GetAsyncKeyState('W') & 0x8000) && (curr_y > 0)) {
        if(where->get_pos(curr_x, curr_y - 1)->can_walk_on()) {
            this->pos->free();
            this->pos = where->get_pos(curr_x, curr_y - 1);
            this->pos->make_character();
        }
        if (this->pos->is_pot()) {
            this->pos->make_grass();
            this->pot_count++;
        }
        return;
    }
    // MOVE DOWN 
    if((GetAsyncKeyState('S') & 0x8000) && (curr_y < where->get_height() - 1)) {
        if(where->get_pos(curr_x, curr_y + 1)->can_walk_on()) {
            this->pos->free();
            this->pos = where->get_pos(curr_x, curr_y + 1);
            this->pos->make_character();
        }
        if (this->pos->is_pot()) {
            this->pos->make_grass();
            this->pot_count++;
        }
        return;
    }
}

int avatar::get_pots() {
    return this->pot_count;
}