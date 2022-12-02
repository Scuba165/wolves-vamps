#include <iostream>
#include <windows.h>
#include "../headers/char.h"
using namespace std;

void character::move() {}

avatar::avatar(board board) {
    this->where = &board;
    cout << "Enter 0 to support Werewolves, 1 to support Vampires: ";
    cin >> this->supp_team;
    this->set_pos(board);
}


void avatar::set_pos(board board) {
    int x = rand() % board.get_width();
    int y = rand() % board.get_height();
    while(board.at(x, y).can_walk_on() == false) {
            x = rand() % board.get_width();
            y = rand() % board.get_height();
    }
    this->pos = board.set_pos(x, y);
    this->pos->make_occupied();
    this->pos->make_character();
} 

void avatar::move() {
    if(this->supp_team) {
        this->pos = where->set_pos((pos->get_x()),((pos->get_y()) - 1));
    }
}