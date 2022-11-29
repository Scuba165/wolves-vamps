

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


    char print() {
        if(this->is_tree) {
            return 'T';
        }
        if(this->is_lake) {
            return 'L';  
        }
        if(this->is_potion) {
            return 'P';
        }
        return 'G';
    }
};