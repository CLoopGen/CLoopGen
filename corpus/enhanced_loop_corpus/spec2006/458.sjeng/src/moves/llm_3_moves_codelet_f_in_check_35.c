#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with variable stride using indirect indexing via a precomputed offset table
    // Simulates irregular access pattern but maintains downward column traversal logic
    static const int offsets[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120}; // Precomputed negative strides as positive offsets
    int base = wking_loc;
    int i;
    for (i = 0; i < 10; i++) {
        l = base - offsets[i];
        if (board[l] != 13) break;
    }
    // Final value of 'l' approximates the exit condition of original loop
}
