#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access with increased stride (simulating a different traversal pattern)
    // Instead of subtracting 11 each time, subtract 22 to create a wider diagonal scan.
    // This maintains the same logic but changes memory access pattern to every other element in the original sequence.
    for (l = bking_loc - 11; board[l] == 13 && l >= 0; l -= 22)
        ;
}
