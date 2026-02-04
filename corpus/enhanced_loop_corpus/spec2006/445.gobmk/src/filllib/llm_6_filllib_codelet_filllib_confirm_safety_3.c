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
    int temp_apear = -1;
    for (k = 4; k < 8; k++) {
        Intersection current = board[move + delta[k]];
        if (current == color) {
            temp_apear = move + delta[k];
        }
    }
    if (temp_apear != -1) {
        apos = temp_apear;
    }
}
