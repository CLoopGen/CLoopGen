#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This changes the access pattern to non-consecutive, stepping through the array with a fixed stride.
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (ii = start; ii < end; ii += 2) {
        if (cached_board[ii] != board[ii]) {
            cached_board[ii] = board[ii];
            board_was_cached = 0;
        }
        int next = ii + 1;
        if (next < end) {
            if (cached_board[next] != board[next]) {
                cached_board[next] = board[next];
                board_was_cached = 0;
            }
        }
    }
}
