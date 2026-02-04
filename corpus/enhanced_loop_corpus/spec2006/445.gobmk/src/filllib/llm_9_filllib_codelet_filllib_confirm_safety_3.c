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
    for (k = 4; k < 12; k++) {
        int offset = (k < 8) ? delta[k] : delta[k - 4];
        if (board[move + offset] == color) {
            apos = move + offset;
            break;
        }
    }
}
