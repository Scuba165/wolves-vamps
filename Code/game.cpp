#include <iostream>
#include "headers/board.h"
#include "headers/char.h"
#include "headers/tile.h"
#include "modules/board.cpp"
#include "modules/char.cpp"
#include "modules/tile.cpp"
using namespace std;

// Ayto tha mpei sto teliko file.
int main() {
    srand(time(0));
    board map = board();
    map.add_objects();
    avatar player = avatar(map);
    map.print_board(); 
}