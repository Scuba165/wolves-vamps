#include <iostream>
#include "tile.cpp" // thelw na kanw include to h alla den to exw vrei
using namespace std;

tile** create_board(int size_x, int size_y) {
    tile** board = new tile*[size_x];
    for(int i = 0; i < size_x; i++ ) {
        board[i] = new tile[size_y];
    }
    return board;
}
// Adds trees, lakes, potion.
void add_objects(tile* board[], int size_x, int size_y) {
    // Trees
    for(int i = 0; i < (size_x*size_y / 15) + 1; i++) {
        int x = rand() % size_x;
        int y = rand() % size_y;
        board[x][y].is_tree = true;
        board[x][y].is_occupied = true;
    }
    // Lakes
    for(int i = 0; i < (size_x*size_y / 20) + 1; i++) {
        int x = rand() % size_x;
        int y = rand() % size_y;
        board[x][y].is_lake = true;
        board[x][y].is_occupied = true;
    }
    // Potion
    int x = rand() % size_x;
    int y = rand() % size_y;
    while(board[x][y].is_occupied) {
        int x = rand() % size_x;
        int y = rand() % size_y;
    }
    board[x][y].is_potion = true;
}

void print_board(tile* board[], int size_x, int size_y) {
    for(int i = 0; i < size_x; i++) {
        for(int j = 0; j < size_y; j++) {
            cout << board[i][j].print() << " ";  
        }
        cout << endl;
    }
}

// Ayto tha mpei sto teliko file.
int main() {
    cout << "Enter map size: ";
    int size_x;
    cin >> size_x;
    int size_y;
    cin >> size_y;
    tile** board = create_board(size_x, size_y);
    add_objects(board, size_x, size_y);
    print_board(board, size_x, size_y);
}