#include "../headers/state.h"

state::state() {
    this->playing = true;
    this->paused = false;
    this->game_over = false;
    this->dn_cycle = 1;
    this->day = false;
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
    if(dn_cycle / 10 == 0) {
        day = true;
        dn_cycle++;
        return;
    }
    day = false;
    dn_cycle++;
    if(dn_cycle == 21) {
        dn_cycle = 1;
    }
}