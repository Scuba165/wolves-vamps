// HEADER FOR CLASS BOARD
#include "../headers/tile.h"
#pragma once

class board {
private:
    tile** map; // Map. [2D tile array].
    int size_x; // Width.
    int size_y; // Height.

public:
board(); // Constructor.
int get_width(); // Returns width of board.
int get_height(); // Returns height of board.
tile at(int, int); // Returns tile of given position.
tile* get_pos(int, int); // Returns pointer to position.
tile** create_board(); // Initializes the board size.
void add_objects(); // Adds trees, lakes, potion.
void print_board(); // Prints board.
};