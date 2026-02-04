#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating cache-friendly pattern)
    int stride = 22; // Double the original step to create a strided access pattern
    for (l = wking_loc - 11; board[l] == 13; l -= stride)
        ;
}
