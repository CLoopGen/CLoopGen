#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with a fixed offset array
    // Simulates irregular access pattern via indexing through a small stride table (e.g., indirect + strided)
    int *ptr = &board[bking_loc + 1];
    int stride_offset = 1;  // Base stride; could simulate variable pattern in more complex cases
    for (l = bking_loc + 1; *(ptr + 0) == 13; l += 1, ptr += stride_offset)
        ;
}
