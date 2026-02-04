#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating cache-friendly pattern)
    int temp = bking_loc - 13;
    for (l = temp; l >= 0 && board[l] == 13; l -= 26)  // Double the stride for sparser access
        ;
}
