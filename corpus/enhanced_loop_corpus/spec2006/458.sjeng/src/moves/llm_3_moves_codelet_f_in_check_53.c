#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int *indices[144];
    for (int i = 0; i < 144; ++i) {
        indices[i] = &board[i];
    }
    int idx = bking_loc - 1;
    for (l = idx; *(indices[l]) == 13; l -= 1) {
        if (l <= 0) break;
    }
}
