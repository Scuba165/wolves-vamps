#include <iostream>
#include <stdlib.h>
#include "headers/board.h"
#include "headers/char.h"
#include "headers/tile.h"
#include "modules/board.cpp"
#include "modules/char.cpp"
#include "modules/tile.cpp"
#include <windows.h>




// Ayto tha mpei sto teliko file.
int main() {
    srand(time(0));
    board map = board();
    map.add_objects();
    avatar player = avatar(map); 
    while(!GetAsyncKeyState('N')) {
        map.print_board();
        Sleep(500);
        player.move(map);
    }
    // Main meta to struct state
    /* while (state->playing) {
            if(!state->paused) {
                do_game_loop(); //print board, update
            }
            if(state->paused) {
                ...
            }
        }
        state->game_over();
    }*/
}