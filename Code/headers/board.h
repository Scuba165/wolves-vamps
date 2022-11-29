// Header for creating the scene.
#include "tile.h"

tile** create_board(int size_x, int size_y); // Initializes the board size.

void add_objects(tile* board[], int size_x, int size_y); // Adds trees, lakes, potion.

void print_board(tile* board[], int size_x, int size_y); // Prints board.
