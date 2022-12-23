#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Werewolf {
public:
    int attack;
    int defense;
    int health;
    int heal;

    void setStats(int a, int d, int h, int he);
    void printStats();
    void move();
};

void Werewolf::setStats(int a, int d, int h, int he) {
    attack = a;
    defense = d;
    health = h;
    heal = he;
}

void Werewolf::printStats() {
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Health: " << health << endl;
    cout << "Heal: " << heal << endl;
}

void Werewolf::move(){

}

int main() {
    int x, y;
    int numWV;
    int numW;
    int at, de, hea;
    
    cout << "Please enter the x coordinate: ";
    cin >> x;
    cout << "Please enter the y coordinate: ";
    cin >> y;

    srand(time(NULL));
    numWV = rand() % (x * y / 15 - 2 + 1) + 2;
    numW = numWV / 2;

    Werewolf* werewolf = new Werewolf[numW];
    for (int i = 0; i < numW; i++) {
        at=(rand() % 3) + 1;
        de=(rand() % 2) + 1;
        hea=rand() % 3;
        werewolf[i].setStats(at, de, 6, hea);
        werewolf[i].printStats();
    }

    delete[] werewolf;
    return 0;
}



