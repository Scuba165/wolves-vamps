// HEADER FOR CLASS STATE
#include "board.h"
#include "char.h"
#include <vector>

class state {
    private:
    bool playing;
    bool paused;
    bool day;
    int dn_cycle;
    avatar* player;
    
    public:
    state(avatar inp);
    bool is_playing();
    bool is_paused();
    void toggle_pause();
    bool is_day();
    void do_dn_cycle();
    void update(board board);
    void pause_menu();
};