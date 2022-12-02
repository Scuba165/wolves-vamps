// TILE HEADER FILE

class tile {
private:
    bool is_tree;
    bool is_lake;
    bool is_potion;
    bool is_occupied;
    bool is_character;
public:
    tile();
    void print();
    void make_tree();
    void make_lake();
    void make_potion();
    bool can_walk_on();
    void operator = (tile& b);
};