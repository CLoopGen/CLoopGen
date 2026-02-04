#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with larger stride (simulating a different traversal pattern)
    // Instead of subtracting 11 each time, subtract 22 to create a wider diagonal-like access pattern.
    // This maintains the idea of traversing in steps but changes the access stride.
    for (l = wking_loc - 11; board[l] == 13 && l >= 0; l -= 22) {
        // Additional bounds check to prevent underflow due to larger step
        if (l < 22) break;
    }
}
