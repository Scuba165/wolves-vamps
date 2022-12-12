#include "../headers/state.h"
#include <iostream>
#include <windows.h>

state::state() {
    this->playing = true;
    this->paused = false;
    this->game_over = false;
    this->dn_cycle = 0;
    this->day = true;
}

void state::toggle_pause() {
    if(this->paused) {
        this->paused = false;
        return;
    }
    this->paused = true;
}

bool state::is_playing() {
    return this->playing;
}

bool state::is_paused() {
    return this->paused;
}

bool state::is_over() {
    return this->game_over;
}

bool state::is_day() {
    return this->day;
}

void state::do_dn_cycle() {
    if(dn_cycle < 10) {
        day = true;
        dn_cycle++;
        return;
    }
    day = false;
    dn_cycle++;
    if(dn_cycle == 20) {
        dn_cycle = 0;
    }
}

void state::update_board(board board) {
    system("CLS");
    if(is_day()) {
        for(int i = 0; i < (board.get_width()/2)-2; i++) { 
            std::cout << "\033[45m   \033[45m";
        }
        std::cout << "\033[45m    NIGHT\033[45m";
        for(int j = 0; j < (board.get_width()/2)-1; j++) { 
            std::cout << "\033[45m   \033[45m";
        }
    }
    if(!is_day()) {
        for(int i = 0; i < (board.get_width()/2)-2; i++) { 
            std::cout << "\033[47m   \033[47m";
        }
        std::cout << "\033[47m    DAY  \033[47m";
        for(int j = 0; j < (board.get_width()/2)-1; j++) { 
            std::cout << "\033[47m   \033[47m";
        }
    }
    do_dn_cycle();
    board.print_board();
    system("PAUSE");
}