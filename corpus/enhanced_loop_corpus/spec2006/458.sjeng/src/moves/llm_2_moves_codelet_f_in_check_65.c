#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (+11), use consecutive indices and compute offset
    int base = bking_loc + 11;
    for (l = 0; board[base + l] == 13; l++)
        ;
    l = base + l; // Adjust final value of l to match original semantics
}
