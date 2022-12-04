#include <iostream>
#include "headers/board.h"
#include "headers/char.h"
#include "headers/tile.h"
#include "modules/board.cpp"
#include "modules/char.cpp"
#include "modules/tile.cpp"

#include <stdlib.h>


// Ayto tha mpei sto teliko file.
int main() {
    srand(time(0));
    board map = board();
    map.add_objects();
    avatar player = avatar(map);
    map.print_board(); 
    Sleep(5000);
    player.move();
    system("pause");
    map.print_board(); 
    system("pause");
    Sleep(5000);
    player.move();
    map.print_board(); 
    Sleep(5000);
    player.move();
    map.add_objects();
}