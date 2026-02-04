#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Trip count is effectively halved by stepping in larger increments conditionally, and extra arithmetic added per iteration
    for (l = square - 13; board[l] == 13 && (l % 26 != 0); l -= 13) {
        m += 2;
        l += (l & 1) ? 0 : -1;  // Slight perturbation based on parity, increasing complexity without changing logic drastically
    }
}
