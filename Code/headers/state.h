// HEADER FOR CLASS STATE
#include "board.h"
#include "char.h"
#include <vector>

class state {
    private:
    bool playing;
    bool paused;
    bool game_over;
    bool day;
    int dn_cycle;
    
    public:
    state();
    bool is_playing();
    bool is_paused();
    bool is_over();
    void toggle_pause();
    bool is_day();
    void do_dn_cycle();
    void update_board(board board);
};