#include <iostream>
#include <stdlib.h>
#include "../headers/char.h"

using namespace std;

class Vampire : public character {
public:
    const int health = 6;
    int attack;
    int defense;
    int medkits;

    Vampire(board map);
    void move(board map);
    void pos_init();
};

Vampire::Vampire(board map) {
    this->where = &map;
    this->pos_init();
    this->attack = (rand() % 3) + 1;
    this->defense = (rand() % 2) + 1;
    this->medkits = rand() % 3;

}

void Vampire::pos_init() {
    int x = rand() % where->get_width();
    int y = rand() % where->get_height();
    while(where->at(x, y).can_walk_on() == false) {
            x = rand() % where->get_width();
            y = rand() % where->get_height();
    }
    this->pos = where->get_pos(x, y);
    this->pos->make_vampire();
} 

void Vampire::move(board map) { 
     this->where = &map;
     int curr_x = this->pos->get_x();
     int curr_y = this->pos->get_y();
     int randDirection = rand() % 8;
     if((randDirection == 0) && (curr_x > 0)) {
         if(where->get_pos(curr_x - 1, curr_y)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x - 1, curr_y);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 1) && (curr_x < where->get_width() - 1)) {
         if(where->get_pos(curr_x + 1, curr_y)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x + 1, curr_y);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 2) && (curr_y > 0)) {
         if(where->get_pos(curr_x, curr_y - 1)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x, curr_y - 1);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 3) && (curr_y < where->get_height() - 1)) {
         if(where->get_pos(curr_x, curr_y + 1)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x, curr_y + 1);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 4) && (curr_x > 0 && curr_y > 0)) {
         if(where->get_pos(curr_x - 1, curr_y - 1)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x - 1, curr_y - 1);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 5) && (curr_x > 0 && curr_y < where->get_height() - 1)) {
         if(where->get_pos(curr_x - 1, curr_y + 1)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x - 1, curr_y + 1);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 6) && (curr_x < where->get_width() - 1 && curr_y > 0)) {
         if(where->get_pos(curr_x + 1, curr_y - 1)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x + 1, curr_y - 1);
             this->pos->make_vampire();
         }
         return;
     }
     else if((randDirection == 7) && (curr_x < where->get_width() - 1 && curr_y < where->get_height() - 1)) {
         if(where->get_pos(curr_x + 1, curr_y + 1)->can_walk_on()) {
             this->pos->free();
             this->pos = where->get_pos(curr_x + 1, curr_y + 1);
             this->pos->make_vampire();
         }
         return;
     }

 }
