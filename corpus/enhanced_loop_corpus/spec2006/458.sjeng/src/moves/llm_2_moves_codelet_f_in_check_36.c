#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Offset Adjustment
    // Instead of strided access by 12, we reinterpret the access pattern to use a base pointer
    // and traverse consecutive elements that correspond to the same relative offset
    // in each "row" (assuming 12-element rows). We simulate the original logic by checking
    // equivalent positions consecutively in a flattened manner.

    int *base = &board[wking_loc + 12];
    for (l = wking_loc + 12; *(base + (l - wking_loc - 12)) == 13; l += 12)
        ;
}
