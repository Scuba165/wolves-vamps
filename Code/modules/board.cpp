#include <iostream>
#include "../headers/board.h"

    // Constructor
    board::board() { 
        std::cout << "Enter map width: ";
        std::cin >> this->size_x;
        std::cout << "Enter map height: ";
        std::cin >> this->size_y;
        this->map = create_board();
    };

    // Access to size
    int board::get_width() {
        return this->size_x;
    }

    int board::get_height() {
        return this->size_y;
    }

    // Create function
    tile** board::create_board() {
        tile** map = new tile*[get_width()];
        for(int i = 0; i < get_width(); i++ ) {
            map[i] = new tile[get_height()];
            for(int j = 0; j < get_height(); j++) {
                map[i][j].set_x(i);
                map[i][j].set_y(j);
            }
        }

        return map;
    }

    // Adds trees, lakes, potion.
    void board::add_objects() {
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

    //Position get
    tile* board::get_pos(int x, int y) {
        return &map[x][y];
    }
    // At
    tile board::at(int x, int y) {
        return map[x][y];
    }

    //Prints board
    void board::print_board() {
        system("CLS");
        for(int i = 0; i < get_height(); i++) {
            for(int j = 0; j < get_width(); j++) {
               at(i, j).print();  
            }
            std::cout << std::endl;
        }
    }


