#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access by 13, simulate same logic using consecutive indexing
    // Map original indices (bking_loc + 13, +26, +39, ...) to a sequential index
    int idx = 1;
    for (l = bking_loc + 13; board[l] == 13; idx++)
        l = bking_loc + 13 * idx;
}
