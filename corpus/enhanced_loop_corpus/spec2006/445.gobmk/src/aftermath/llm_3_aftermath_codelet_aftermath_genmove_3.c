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
for (k = 0; k < 4; k++) {
    int index = delta[k];
    int pos2 = move + index;
    int dist_index = distance[move] - 1;
    if ((board[pos2] != 3) && board[pos2] == 0 && distance[pos2] == dist_index) {
        move = pos2;
        break;
    }
}
}
