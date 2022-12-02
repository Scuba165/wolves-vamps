// Header for creating the scene.
#include "../headers/tile.h"

class board {
private:
    tile** map;
    int size_x;
    int size_y;

public:
board();
int get_width();
int get_height();
tile set_pos(int, int);
tile** create_board(); // Initializes the board size.
void add_objects(); // Adds trees, lakes, potion.
void print_board(); // Prints board.
};