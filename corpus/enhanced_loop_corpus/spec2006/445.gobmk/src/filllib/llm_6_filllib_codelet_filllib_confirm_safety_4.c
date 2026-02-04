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
    Intersection temp_color = color;
    int temp_move = move;
    int delta_local[4];
    for (int i = 0; i < 4; i++) {
        delta_local[i] = delta[i];
    }
    apos = -1;
    for (k = 0; k < 4; k++) {
        int index = temp_move + 2 * delta_local[k];
        if (board[index] == temp_color) {
            apos = index;
            break;
        }
    }
}
