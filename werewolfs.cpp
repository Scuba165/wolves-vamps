#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void moveWerewolf(char map[][],int x, int y, int &XpositionW, int &YpositionW) {
  
  int randDirection = rand() % 4;

  
   if( randDirection == 0){
      if (XpositionW > 0) {
        map[XpositionW][YpositionW] = '-';
        XpositionW--;
        map[XpositionW][YpositionW] = 'w';
      }
   }
   else if( randDirection == 1){
      if (YpositionW < y) {
        map[XpositionW][YpositionW] = '-';
        YpositionW++;
        map[XpositionW][YpositionW] = 'w';
      }
   }
    else if( randDirection == 2){
      if (XpositionW < x) {
        map[XpositionW][YpositionW] = '-';
        XpositionW++;
        map[XpositionW][YpositionW] = 'w';
      }
    }
    else if( randDirection ==3){
      if (YpositionW > 0) {
        map[XpositionW][YpositionW] = '-';
        YpositionW--;
        map[XpositionW][YpositionW] = 'w';
      }
    }
}

void moveVampire(char map[][],int x ,int y, int &XpositionV, int &YpositionV) {
  
  int randDirection = rand() % 8;

  
   if( randDirection == 0){
      if (XpositionV > 0) {
        map[XpositionV][YpositionV] = '-';
        XpositionV--;
        map[XpositionV][YpositionV] = 'v';
      }
   }
   else if( randDirection == 1){
      if (YpositionV < y) {
        map[XpositionV][YpositionV] = '-';
        YpositionV++;
        map[XpositionV][YpositionV] = 'v';
      }
   }
    else if( randDirection == 2){
      if (XpositionV < x) {
        map[XpositionV][YpositionV] = '-';
        XpositionV++;
        map[XpositionV][YpositionV] = 'v';
      }
    }
    else if( randDirection ==3){
      if (YpositionV > 0) {
        map[XpositionV][YpositionV] = '-';
        YpositionV--;
        map[XpositionV][YpositionV] = 'v';
      }
    }
    else if( randDirection == 4){
     if (YpositionV > 0 && XpositionV <x){
      map[XpositionV][YpositionV] = '-';
      XpositionV++;
      YpositionV--;
      map[XpositionV][YpositionV] = 'v';
     }
    }
    else if( randDirection ==5){
     if (YpositionV >0 && XpositionV >0){
      map[XpositionV][YpositionV] = '-';
      XpositionV--;
      YpositionV--;
      map[XpositionV][YpositionV] = 'v';
     }   
    }
    else if( randDirection ==6){
     if (YpositionV <y && XpositionV>0){
      map[XpositionV][YpositionV] = '-';
      XpositionV--;
      YpositionV++;
      map[XpositionV][YpositionV] = 'v';
     }   
    }
    else if( randDirection ==7){
     if (YpositionV <y && XpositionV<x){
      map[XpositionV][YpositionV] = '-';
      XpositionV++;
      YpositionV++;
      map[XpositionV][YpositionV] = 'v';
     }   
    }
}

int main() {
  
  int x, y;
  int numWV;
  char map[x][y];
 
  cout << "Please enter the x coordinate: ";
  cin >> x;
  cout << "Please enter the y coordinate: ";
  cin >> y;

  srand(time(NULL));
  numWV = rand() % (x*y/15 - 2 + 1) + 2;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      map[i][j] = '-';
    }
  }

  int countW = 0;
  int countV = 0;
  while (countW < numWV || countV < numWV) {
    int randX = rand() % x;
    int randY = rand() % y;
    if (map[randX][randY] == '-') {
      if (countW < numWV) {
        map[randX][randY] = 'w';
        countW++;
      } else if (countV < numWV) {
        map[randX][randY] = 'v';
        countV++;
      }
    }
  }
  // na ksero se poia thesi einai
  int XpositionW[numWV];
  int YpositionW[numWV];
  int XpositionV[numWV];
  int YpositionV[numWV];
  int w = 0;
  int v = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (map[i][j] == 'w') {
        XpositionW[w] = i;
        YpositionW[w] = j;
        w++;
      } else if (map[i][j] == 'v') {
        XpositionV[v] = i;
        YpositionV[v] = j;
        v++;
      }
    }
  }

    for (int i = 0; i < numWV; i++) {
      moveWerewolf(map, x, y, XpositionW[i], YpositionW[i]);
    }

 
    for (int i = 0; i < numWV; i++) {
      moveVampire(map, x, y, XpositionV[i], YpositionV[i]);
    }


    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        cout << map[i][j];
      }
      cout << endl;
    }
  return 0;
}