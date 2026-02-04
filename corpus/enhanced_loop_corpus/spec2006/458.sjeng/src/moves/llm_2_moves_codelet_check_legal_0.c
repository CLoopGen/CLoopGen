#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating cache-friendly pattern or different grid traversal)
    int stride = 24; // Double the original step to create a strided access pattern
    for (l = bking_loc - 12; l >= 0 && board[l] == 13; l -= stride)
        ;
}
