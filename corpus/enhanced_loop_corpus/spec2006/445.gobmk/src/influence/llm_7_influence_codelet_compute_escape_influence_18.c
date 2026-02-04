#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_cached_value, new_cached_value;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        prev_cached_value = cached_board[ii];
        new_cached_value = board[ii];
        cached_board[ii] = new_cached_value;
        if (prev_cached_value != new_cached_value) {
            board_was_cached = 0;
        }
    }
}
