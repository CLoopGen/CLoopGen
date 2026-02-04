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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing delta[0..3] sequentially, access with a stride of 2 (delta[0], delta[2])
    // Duplicate the logic to maintain similar behavior with modified access pattern.
    for (k = 0; k < 4; k += 2) {
        if (board[move + 2 * delta[k]] == color) {
            apos = move + 2 * delta[k];
            break;
        }
        // Check next element in-line to preserve coverage of all 4 indices
        if (k + 1 < 4 && board[move + 2 * delta[k + 1]] == color) {
            apos = move + 2 * delta[k + 1];
            break;
        }
    }
}
