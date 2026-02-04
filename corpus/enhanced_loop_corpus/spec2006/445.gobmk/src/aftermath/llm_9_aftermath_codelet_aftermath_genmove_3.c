#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int k;
extern int distance[400];
extern int move;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 1;
for (k = 0; k < 4; k += step) {
    int pos2 = move + delta[k];
    int d_move = distance[move];
    int d_pos2 = distance[pos2];
    if ((board[pos2] != 3) && (board[pos2] == 0) && (d_pos2 == d_move - 1)) {
        move = pos2;
        step = 2; // Alter flow slightly by changing increment
    }
}
}
