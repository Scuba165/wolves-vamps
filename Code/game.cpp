#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/board.h"
#include "headers/char.h"
#include "headers/tile.h"
//#include "headers/state.h"
#include "modules/board.cpp"
#include "modules/char.cpp"
#include "modules/tile.cpp"
#include "modules/state.cpp"
#include "modules/werewolf.cpp"
#include "modules/vampire.cpp"
#include <windows.h>

int main() {
    int rounds = 0;
    srand(time(0));
    board map = board();
    map.add_objects();
    avatar player = avatar(map);
    state gamestate = state(player);
    int entities = (map.get_height() * map.get_width() / 40);
    std::vector<Werewolf> Werewolves;
    std::vector<Vampire> Vampires; 
    for(int i = 0; i < entities; i++) {
        Werewolves.push_back(Werewolf(map));
        Vampires.push_back(Vampire(map));
    }
    while(gamestate.is_playing()) {
        if(gamestate.is_paused()) {
            gamestate.pause_menu(Werewolves, Vampires, player);
        }
        player.move(map);
        for(int i = 0; i < Werewolves.size(); i++) {
            if(Werewolves.at(i).health <= 0) {
                Werewolves.at(i).killed();
                Werewolves.erase(Werewolves.begin()+i);
            }
            Werewolves.at(i).move(map);
        }
        for(int i = 0; i < Vampires.size(); i++) {
             if(Vampires.at(i).health <= 0) {
                Vampires.at(i).killed();
                Vampires.erase(Vampires.begin()+i);
            }
            Vampires.at(i).move(map);
        }
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
    system("CLS");
}