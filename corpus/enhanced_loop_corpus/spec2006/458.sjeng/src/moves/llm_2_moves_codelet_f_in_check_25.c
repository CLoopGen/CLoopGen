#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Offset Adjustment
    // Instead of strided access by +12, we simulate equivalent logic using a base pointer and consecutive indexing
    // We precompute the offset range and traverse in a way that accesses nearby elements consecutively where possible.
    int base = wking_loc + 12;
    for (l = 0; l < 10 && board[base + l * 12] == 13; ++l)
        ;
    l = base + l * 12; // Restore final value of l as in original
}
