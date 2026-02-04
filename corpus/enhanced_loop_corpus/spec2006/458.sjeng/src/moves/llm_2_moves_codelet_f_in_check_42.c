#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access by -13, we convert the index sequence into a consecutive pattern
    // by precomputing valid indices in a strided manner but iterating consecutively over them.
    int stride = -13;
    int current = bking_loc + stride;
    int temp_index;

    for (int i = 0; (temp_index = current + i * stride) >= 0 && temp_index < 144 && board[temp_index] == 13; ++i)
        ;
}
