#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled stride simulation)
    // Instead of accessing every 12th element backward, we keep the same logic but simulate
    // a more cache-friendly access by ensuring alignment and direct indexing.
    int base = square - 12;
    for (l = base; l >= 0 && board[l] == 13; l -= 12) {
        m++;
    }
}
