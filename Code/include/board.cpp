#include <iostream>
#include "tile.cpp" // thelw na kanw include to h alla den to exw vrei
using namespace std;



class board {
    private:
    tile** map;
    int size_x;
    int size_y;

    public:
    // Constructor
    board() { 
        cout << "Enter map width: ";
        cin >> this->size_x;
        cout << "Enter map height: ";
        cin >> this->size_y;
        map = create_board();
    };

    // Access to size
    int get_width() {
        return this->size_x;
    }

    int get_height() {
        return this->size_y;
    }

    // Create function
    tile** create_board() {
        tile** map = new tile*[get_width()];
        for(int i = 0; i < get_width(); i++ ) {
            map[i] = new tile[get_height()];
        }
        return map;
    }

    // Adds trees, lakes, potion.
    void add_objects() {
        int x = rand() % get_width();
        int y = rand() % get_height();
        // Trees
        for(int i = 0; i < (get_width()*get_height() / 15) + 1; i++) {
            x = rand() % get_width();
            y = rand() % get_height();
            map[x][y].make_tree();
        }
        // Lakes
        for(int i = 0; i < (get_width()*get_height() / 20) + 1; i++) {
            x = rand() % get_width();
            y = rand() % get_height();
            while(map[x][y].can_walk_on() == false) {
                x = rand() % get_width();
                y = rand() % get_height();
            }   
            map[x][y].make_lake();
        }
        // Potion
        
        while(map[x][y].can_walk_on() == false) {
            x = rand() % get_width();
            y = rand() % get_height();
        }
        map[x][y].make_potion();
    }

    //Prints board
    void print_board() {
        system("CLS");
        for(int i = 0; i < get_height(); i++) {
            for(int j = 0; j < get_width(); j++) {
                map[j][i].print();  
            }
            cout << endl;
        }
    }
};

// Ayto tha mpei sto teliko file.
int main() {
    srand(time(0));
    board map;
    map.add_objects();
    map.print_board();
}