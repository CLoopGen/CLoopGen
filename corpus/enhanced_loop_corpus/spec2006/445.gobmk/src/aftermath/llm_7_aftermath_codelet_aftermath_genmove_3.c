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
    int found = 0;
    for (k = 0; k < 4 && !found; k++) {
        int pos2 = move + delta[k];
        int d_move = distance[move] - 1;
        int board_val = board[pos2];
        int dist_val = distance[pos2];
        if ((board_val != 3) && board_val == 0 && dist_val == d_move) {
            move = pos2;
            found = 1;
        }
    }
}
