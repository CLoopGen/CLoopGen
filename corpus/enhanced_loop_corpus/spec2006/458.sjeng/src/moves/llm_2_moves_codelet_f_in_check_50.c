#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    int temp = bking_loc + 12;
    for (l = temp; board[l] == 13; ) {
        l++;
        l += 11; // Equivalent to adding 12, but breaks stride into two steps (consecutive-like increment pattern)
    }
}
