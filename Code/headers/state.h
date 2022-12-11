// HEADER FOR CLASS STATE

class state {
    private:
    bool playing;
    bool paused;
    bool game_over;
    int dn_cycle;
    
    public:
    void is_playing();
    void is_paused();
    void is_over();
    void do_dn_cycle();
};