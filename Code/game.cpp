#include <iostream>
#include <stdlib.h>
#include "headers/board.h"
#include "headers/char.h"
#include "headers/tile.h"
#include "modules/board.cpp"
#include "modules/char.cpp"
#include "modules/tile.cpp"




// Ayto tha mpei sto teliko file.
int main() {
    srand(time(0));
    board map = board();
    map.add_objects();
    avatar player = avatar(map);
    map.print_board(); 
    Sleep(5000);
    player.move();
    std::cout << "Player moved";
    system("pause");
    map.print_board(); 
    system("pause");
    Sleep(5000);
    player.move();
    map.print_board(); 
    Sleep(5000);
    player.move();
}