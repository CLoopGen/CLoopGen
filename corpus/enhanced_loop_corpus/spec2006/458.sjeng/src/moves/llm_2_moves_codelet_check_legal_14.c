#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with larger stride (simulating a different traversal pattern)
    // Instead of decrementing by 11, use a multiple to create a more spaced-out access pattern
    int stride = 22; // Double the original step
    for (l = wking_loc - stride; board[l] == 13; l -= stride)
        ;
}
