#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access (-11), we use a lookup table to simulate consecutive array traversal
    // that still targets the same logical positions relative to bking_loc.
    int index = 0;
    int offsets[] = { -11, -22, -33, -44, -55, -66, -77, -88, -99, -110, -121, -132 }; // Precomputed strides
    for (index = 0; index < 12 && (l = bking_loc + offsets[index], board[l] == 13); index++)
        ;
}
