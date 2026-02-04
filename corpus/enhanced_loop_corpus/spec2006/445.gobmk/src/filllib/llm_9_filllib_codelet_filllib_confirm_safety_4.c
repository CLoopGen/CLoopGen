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
    for (k = 0; k < 6; k++) {
        int offset1 = move + 2 * delta[k];
        int offset2 = move - 2 * delta[k];
        if (board[offset1] == color) {
            apos = offset1;
            break;
        }
        if (board[offset2] == color) {
            apos = offset2;
            break;
        }
    }
}
