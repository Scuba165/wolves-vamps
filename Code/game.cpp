#include <iostream>
#include <stdlib.h>
#include "headers/board.h"
#include "headers/char.h"
#include "headers/tile.h"
// #include "headers/state.h"
#include "modules/board.cpp"
#include "modules/char.cpp"
#include "modules/tile.cpp"
#include "modules/state.cpp"
#include <windows.h>




// Ayto tha mpei sto teliko file.
int main() {
    int rounds = 0;
    srand(time(0));
    board map = board();
    map.add_objects();
    avatar player = avatar(map);
    state gamestate = state(player);
    while(gamestate.is_playing()) {
        if(gamestate.is_paused()) {
            gamestate.pause_menu();
        }
        player.move(map);
        gamestate.update(map);
        rounds++;
    }
    system("CLS");
    for(int i = 0; i < (map.get_width()/2)-2; i++) { 
        std::cout << "\033[41m   \033[41m";
    }
    std::cout << "\033[41mGAME OVER\033[41m";
    for(int j = 0; j < (map.get_width()/2)-1; j++) { 
        std::cout << "\033[41m   \033[41m";
    }
    map.print_board();
    std::cout << "\e[1;31mSomeone would have won but they aren't coded yet!\e[0m" << std::endl;
    std::cout << "\e[1;31mThe game lasted \e[1;31m" << rounds << "\e[1;31m turns\e[1;31m" << std::endl;
    system("PAUSE");
    std::cout << "\e[0m";
}