#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 21;
int end = 361;
for (ii = start; ii < end; ii += 2) {
    int idx = ii + 1;
    if (idx < end && cached_board[idx] != board[idx]) {
        cached_board[idx] = board[idx];
        board_was_cached = 0;
    }
}
}
