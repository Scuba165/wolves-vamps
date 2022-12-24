#include <iostream>
#include <stdlib.h>
#include "../headers/char.h"

using namespace std;

class Werewolf : public character {
public:
    const int health = 6;
    int attack;
    int defense;
    int medkits;

    Werewolf(board map);
    void move(board map);
    void pos_init();
};

Werewolf::Werewolf(board map) {
    this->where = &map;
    this->pos_init();
    this->attack = (rand() % 3) + 1;
    this->defense = (rand() % 2) + 1;
    this->medkits = rand() % 3;

}

void Werewolf::pos_init() {
    int x = rand() % where->get_width();
    int y = rand() % where->get_height();
    while(where->at(x, y).can_walk_on() == false) {
            x = rand() % where->get_width();
            y = rand() % where->get_height();
    }
    this->pos = where->get_pos(x, y);
    this->pos->make_werewolf();
} 

void Werewolf::move(board map) {} // + rand direction kai GetKey -> result
//     this->where = &map;
//     int curr_x = this->pos->get_x();
//     int curr_y = this->pos->get_y();
//     // MOVE LEFT
//     if((GetAsyncKeyState('A') & 0x8000) && (curr_x > 0)) {
//         if(where->get_pos(curr_x - 1, curr_y)->can_walk_on()) {
//             this->pos->free();
//             this->pos = where->get_pos(curr_x - 1, curr_y);
//             this->pos->make_character();
//         }
//         if (this->pos->is_pot()) {
//             this->pos->make_grass();
//             pot_count++;
//         }
//         return;
//     }
//     // MOVE RIGHT
//     if((GetAsyncKeyState('D') & 0x8000) && (curr_x < where->get_width() - 1)) {
//         if(where->get_pos(curr_x + 1, curr_y)->can_walk_on()) {
//             this->pos->free();
//             this->pos = where->get_pos(curr_x + 1, curr_y);
//             this->pos->make_character();
//         }
//         if (this->pos->is_pot()) {
//             this->pos->make_grass();
//             pot_count++;
//         }
//         return;
//     }
//     // MOVE UP
//     if((GetAsyncKeyState('W') & 0x8000) && (curr_y > 0)) {
//         if(where->get_pos(curr_x, curr_y - 1)->can_walk_on()) {
//             this->pos->free();
//             this->pos = where->get_pos(curr_x, curr_y - 1);
//             this->pos->make_character();
//         }
//         if (this->pos->is_pot()) {
//             this->pos->make_grass();
//             pot_count++;
//         }
//         return;
//     }
//     // MOVE DOWN 
//     if((GetAsyncKeyState('S') & 0x8000) && (curr_y < where->get_height() - 1)) {
//         if(where->get_pos(curr_x, curr_y + 1)->can_walk_on()) {
//             this->pos->free();
//             this->pos = where->get_pos(curr_x, curr_y + 1);
//             this->pos->make_character();
//         }
//         if (this->pos->is_pot()) {
//             this->pos->make_grass();
//             pot_count++;
//         }
//         return;
//     }

// }

// int main() {
//     int x, y;
//     int numWV;
//     int numW;
//     int at, de, hea;
    
//     cout << "Please enter the x coordinate: ";
//     cin >> x;
//     cout << "Please enter the y coordinate: ";
//     cin >> y;

//     srand(time(NULL));
//     numWV = rand() % (x * y / 15 - 2 + 1) + 2;
//     numW = numWV / 2;

//     Werewolf* werewolf = new Werewolf[numW];
//     for (int i = 0; i < numW; i++) {
//         at=(rand() % 3) + 1;
//         de=(rand() % 2) + 1;
//         hea=rand() % 3;
//         werewolf[i].setStats(at, de, 6, hea);
//         werewolf[i].printStats();
//     }

//     delete[] werewolf;
//     return 0;
// }



