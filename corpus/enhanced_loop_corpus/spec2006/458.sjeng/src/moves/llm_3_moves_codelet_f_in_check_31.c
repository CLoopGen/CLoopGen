#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using index array (strided access through lookup table)
    int indices[12]; // Assume maximum chain length limits iterations
    int base = wking_loc + 11;
    int step = 11;
    // Precompute indirect access pattern
    for (int i = 0; i < 12; ++i) {
        indices[i] = base + i * step;
    }
    // Traverse using indirect indexing
    for (l = base; board[indices[(l - base)/step]] == 13 && (l - base) % step == 0; l += step) {
        if ((l - base) / step + 1 >= 12) break; // Prevent out of bounds
    }
}
