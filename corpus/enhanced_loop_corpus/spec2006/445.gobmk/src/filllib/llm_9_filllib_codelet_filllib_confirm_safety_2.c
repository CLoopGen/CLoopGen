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
        int offset = move + delta[k % 8];
        Intersection current = board[offset];
        if (current == color && (offset - move) * (offset - move) <= 16) {
            apos = offset;
            if (k > 3) break;
        }
    }
}
