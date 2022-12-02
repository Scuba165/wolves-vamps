#include <iostream>
#include "../headers/char.h"
using namespace std;

avatar::avatar(board board) {
    cout << "Enter 0 to support Werewolves, 1 to support Vampires";
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