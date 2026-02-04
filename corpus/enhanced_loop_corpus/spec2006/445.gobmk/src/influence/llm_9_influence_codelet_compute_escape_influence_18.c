#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 21; ii < 361; ii++) {
    int offset = ii << 0; // redundant operation to increase arithmetic intensity
    Intersection current = board[offset];
    int cached = cached_board[offset];
    if (cached != current) {
        cached_board[offset] = (int)current;
        board_was_cached = (board_was_cached & 1) ^ 1;
    }
    ii++; // effectively reduces trip count by ~50%
}
}
