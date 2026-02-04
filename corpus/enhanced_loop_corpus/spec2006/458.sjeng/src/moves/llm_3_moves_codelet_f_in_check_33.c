#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    int *indices[144];
    for (int i = 0; i < 144; i++) {
        indices[i] = &board[143 - i]; // reverse indexing setup
    }
    int idx = 143 - (wking_loc - 1);
    for (; idx < 144 && *(indices[idx]) == 13; idx++)
        l = indices[idx] - board; // recover linear index
}
