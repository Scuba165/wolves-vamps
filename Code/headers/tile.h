// TILE HEADER FILE

class tile {
    public:
    bool is_tree = 0;
    bool is_lake = 0;
    bool is_potion = 0;
    bool is_occupied = 0;

    char print() {
        if(is_tree) {
            return 'T';
        }
        if(is_lake) {
            return 'L';  
        }
        if(is_potion) {
            return 'P';
        }
        return 'G';
    }
    };