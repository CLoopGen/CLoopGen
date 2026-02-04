#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (+11), traverse consecutive elements
    // Adjust starting point and condition to maintain realistic bounds
    int start = bking_loc + 1;
    for (l = start; l < start + 13 && board[l] == 13; ++l)
        ;
}
