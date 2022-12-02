#include <iostream>
#include "../headers/char.h"
#include "../headers/board.h"
using namespace std;

avatar::avatar(board board) {
    cout << "Enter 0 to support Werewolves, 1 to support Vampires";
    cin >> this->supp_team;
    int x = rand() % board.get_width();
    int y = rand() % board.get_height();
    pos = board.set_pos(x, y);
}
