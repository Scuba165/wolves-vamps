#include "../headers/state.h"
#include <iostream>
#include <windows.h>

state::state(avatar inp) {
    player = &inp;
    this->playing = true;
    this->paused = false;
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

void state::update(board board) {
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
    if(GetAsyncKeyState('P')) {
        toggle_pause();
    }
    if(GetAsyncKeyState('N')) {
        this->playing = false;
    }
    Sleep(500);
}

void state::pause_menu(std::vector<Werewolf> Werewolves, std::vector<Vampire> Vampires, avatar player) {
    std::cout << "\e[1;31mGame is paused. Press 'P' to resume or 'N' to end the game!\e[1;31m" << std::endl;
    std::cout << "\e[1;31mPlayer has \e[1;31m" << player.get_pots() << "\e[1;31m potion(s) left.\e[1;31m" << std::endl;
    std::cout << "\e[1;31mThere are \e[1;31m" << Werewolves.size() << "\e[1;31m Werewolves alive. \e[1;31m" << std::endl;
    std::cout << "\e[1;31mThere are \e[1;31m" << Vampires.size() << "\e[1;31m Vampires alive. \e[1;31m" << std::endl;
    if(GetAsyncKeyState('P') & 0x8000) {
        toggle_pause();
    }
    if(GetAsyncKeyState('N') & 0x8000) {
        this->playing = false;
    }
    system("PAUSE");
    std::cout << "\e[0m";
}