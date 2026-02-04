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
    int local_k;
    int found = 0;
    for (local_k = 4; local_k < 8 && !found; local_k++) {
        int offset = move + delta[local_k];
        Intersection val = board[offset];
        if (val == color) {
            apos = offset;
            found = 1;
        }
    }
    k = local_k - 1;
}
