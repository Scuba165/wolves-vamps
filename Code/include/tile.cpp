#include <iostream>
using namespace std;

class tile {
private:
    bool is_tree;
    bool is_lake;
    bool is_potion;
    bool is_occupied;

public:
    tile() {
        this->is_tree = 0;
        this->is_lake = 0;
        this->is_potion = 0;
        this->is_occupied = 0;
    }

    void make_tree() {
        this->is_tree = true;
        this->is_occupied = true;
    }

    void make_lake() {
        this->is_lake = true;
        this->is_occupied = true;
    }

    void make_potion() {
        this->is_potion = true;
    }
    
    bool can_walk_on() {
        return (!this->is_occupied);
    }


    void print() {
        if(this->is_tree) {
            cout << "\033[42;35m ♣ \033[0m";
            return;
        }
        if(this->is_lake) {
            cout << "\033[;44m   \033[0m";
            return;  
        }
        if(this->is_potion) {
            cout << "\033[42;35m § \033[0m";
            return;
        }
        cout << "\033[;42m   \033[0m";
        return;
    }
};