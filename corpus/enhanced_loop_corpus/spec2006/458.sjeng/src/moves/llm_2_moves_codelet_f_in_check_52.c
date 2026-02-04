#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element instead of consecutive)
    // This changes the traversal pattern but maintains termination condition relative to original logic
    for (l = bking_loc + 1; board[l] == 13; l += 2)
        ;
}
