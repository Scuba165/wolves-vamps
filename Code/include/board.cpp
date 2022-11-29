#include <iostream>
#include "tile.cpp" // thelw na kanw include to h alla den to exw vrei
using namespace std;

tile** create_board(int size) {
    tile** board = new tile*[size];
    for(int i = 0; i < size; i++ ) {
        board[i] = new tile[size];
    }
    return board;
}
// Adds trees, lakes, potion.
void add_objects(tile* board[], int size) {
    // Trees
    for(int i = 0; i < (size*size / 15) + 1; i++) {
        int x = rand() % size;
        int y = rand() % size;
        board[x][y].is_tree = true;
        board[x][y].is_occupied = true;
    }
    // Lakes
    for(int i = 0; i < (size*size / 20) + 1; i++) {
        int x = rand() % size;
        int y = rand() % size;
        board[x][y].is_lake = true;
        board[x][y].is_occupied = true;
    }
    // Potion
    int x = rand() % size;
    int y = rand() % size;
    while(board[x][y].is_occupied) {
        int x = rand() % size;
        int y = rand() % size;
    }
    board[x][y].is_potion = true;
}

void print_board(tile* board[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << board[i][j].print() << " ";  
        }
        cout << endl;
    }
}

// Ayto tha mpei sto teliko file.
int main() {
    cout << "Enter map size: ";
    int size;
    cin >> size;
    tile** board = create_board(size);
    add_objects(board, size);
    print_board(board, size);
}