#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with arithmetic)
    // Access pattern is now indirect via computed indices, mimicking irregular access.
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int size = end - start;
    for (ii = 0; ii < size; ii++) {
        int idx = start + (ii ^ (ii >> 1)); // Simple bit-manipulation to create non-sequential access
        if (idx >= end) continue;
        if (cached_board[idx] != board[idx]) {
            cached_board[idx] = board[idx];
            board_was_cached = 0;
        }
    }
}
