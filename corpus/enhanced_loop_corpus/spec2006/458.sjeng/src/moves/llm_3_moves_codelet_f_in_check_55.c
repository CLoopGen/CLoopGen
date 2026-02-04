#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using an offset array to simulate indirect indexing
    int indices[] = {bking_loc - 13, bking_loc - 26, bking_loc - 39, bking_loc - 52}; // Predefined access path
    int i;
    for (i = 0; i < 4; i++) {
        l = indices[i];
        if (board[l] != 13) break;
    }
}
