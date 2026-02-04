#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int move;
extern int color;
extern int k;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 8; k += 2) {
        if (board[move + delta[k]] == color) {
            apos = move + delta[k];
            break;
        }
        if (k + 1 < 8 && board[move + delta[k + 1]] == color) {
            apos = move + delta[k + 1];
            break;
        }
    }
}
