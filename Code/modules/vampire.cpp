#include <iostream>
#include <stdlib.h>
#include "../headers/char.h"

Vampire::Vampire(board map) {
    this->health = 6;
    this->where = &map;
    this->pos_init();
    this->damage = (rand() % 3) + 1;
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

tile* Vampire::get_pos() {
    return this->pos;
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

void Vampire::scan(board map, std::vector<Vampire> vamps, std::vector<Werewolf> ww) {
    this->where = &map;
    int curr_x = this->pos->get_x();
    int curr_y = this->pos->get_y();
    Werewolf enemy = ww.front();
    Vampire ally = vamps.front();
    // Check attack left
    if(this->where->at(curr_x - 1, curr_y).is_werewolf()) {
        for(int i = 0; i < ww.size(); i++) {
            if(ww.at(i).get_pos()->get_x() == curr_x - 1 && ww.at(i).get_pos()->get_y() == curr_y) {
                enemy = ww.at(i);
                break;
            }
        }
        if(enemy.damage < this->damage) {  
            enemy.health -= this->damage - enemy.defense;
        }
        if(enemy.damage > this->damage) {
            this->move(map);
        }
        return;
    }
    // Check attack right
    if(this->where->at(curr_x + 1, curr_y).is_werewolf()) {
        for(int i = 0; i < ww.size(); i++) {
            if(ww.at(i).get_pos()->get_x() == curr_x + 1 && ww.at(i).get_pos()->get_y() == curr_y) {
                enemy = ww.at(i);
                break;
            }
        }
        if(enemy.damage < this->damage) {  
            enemy.health -= this->damage - enemy.defense;
        }
        if(enemy.damage > this->damage) {
            this->move(map);
        }
        return;
    }
    // Check attack up
    if(this->where->at(curr_x, curr_y - 1).is_werewolf()) {
        for(int i = 0; i < ww.size(); i++) {
            if(ww.at(i).get_pos()->get_x() == curr_x && ww.at(i).get_pos()->get_y() == curr_y - 1) {
                enemy = ww.at(i);
                break;
            }
        }
        if(enemy.damage < this->damage) {  
            enemy.health -= this->damage - enemy.defense;
        }
        if(enemy.damage > this->damage) {
            this->move(map);
        }
        return;
    }
    // Check attack down
    if(this->where->at(curr_x, curr_y + 1).is_werewolf()) {
        for(int i = 0; i < ww.size(); i++) {
            if(ww.at(i).get_pos()->get_x() == curr_x && ww.at(i).get_pos()->get_y() == curr_y + 1) {
                enemy = ww.at(i);
                break;
            }
        }
        if(enemy.damage < this->damage) {  
            enemy.health -= this->damage - enemy.defense;
        }
        if(enemy.damage > this->damage) {
            this->move(map);
        }
        return;
    }
    // Check heal left
    if(this->where->at(curr_x - 1, curr_y).is_vampire()) {
        for(int i = 0; i < vamps.size(); i++) {
            if(vamps.at(i).get_pos()->get_x() == curr_x - 1 && vamps.at(i).get_pos()->get_y() == curr_y) {
                ally = vamps.at(i);
                break;
            }
        }
        if(ally.health < 6 && this->medkits > 0) {  
            ally.health++;
            this->medkits--;
        }
        return;
    }
    // Check heal right
    if(this->where->at(curr_x + 1, curr_y).is_vampire()) {
        for(int i = 0; i < vamps.size(); i++) {
            if(vamps.at(i).get_pos()->get_x() == curr_x + 1 && vamps.at(i).get_pos()->get_y() == curr_y) {
                ally = vamps.at(i);
                break;
            }
        }
        if(ally.health < 6 && this->medkits > 0) {  
            ally.health++;
            this->medkits--;
        }
        return;
    }
    // Check heal up
    if(this->where->at(curr_x, curr_y - 1).is_vampire()) {
        for(int i = 0; i < vamps.size(); i++) {
            if(vamps.at(i).get_pos()->get_x() == curr_x && vamps.at(i).get_pos()->get_y() == curr_y - 1) {
                ally = vamps.at(i);
                break;
            }
        }
        if(ally.health < 6 && this->medkits > 0) {  
            ally.health++;
            this->medkits--;
        }
        return;
    }
    // Check heal down
    if(this->where->at(curr_x, curr_y + 1).is_vampire()) {
        for(int i = 0; i < vamps.size(); i++) {
            if(vamps.at(i).get_pos()->get_x() == curr_x &&vamps.at(i).get_pos()->get_y() == curr_y + 1) {
                ally = vamps.at(i);
                break;
            }
        }
        if(ally.health < 6 && this->medkits > 0) {  
            ally.health++;
            this->medkits--;
        }
        return;
    }
}

void Vampire::killed() {
    this->pos->free();
    delete this;
}