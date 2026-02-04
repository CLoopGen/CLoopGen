#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access by 12, we simulate the same logical behavior using a base pointer and consecutive indexing
    int *base = board + wking_loc;
    for (l = 12; *(base + l) == 13; l += 12)
        ;
}
