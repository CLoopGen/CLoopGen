#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element backward)
    int stride = 2;
    for (l = bking_loc - 1; l >= 0 && board[l] == 13; l -= stride) {
        // Perform check with strided access; ensure bounds safety
        if (l - stride < 0 || board[l - stride] != 13) break;
    }
    // Adjust l to point to the correct exit location (last valid index where condition failed or stride boundary)
    while (l + stride < bking_loc && board[l + stride] == 13) l += stride;
}
