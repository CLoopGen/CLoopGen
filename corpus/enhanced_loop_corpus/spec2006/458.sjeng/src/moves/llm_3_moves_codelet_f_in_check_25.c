#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Array Access via Index Mapping
    // Use an auxiliary index array to perform indirect memory access, simulating irregular or data-dependent traversal
    // This reflects scenarios like sparse traversal or when access pattern is computed dynamically
    static const int stride_offsets[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120}; // Precomputed offsets from base
    int base = wking_loc + 12;
    int i;
    for (i = 0; i < 10; ++i) {
        l = base + stride_offsets[i];
        if (board[l] != 13) break;
    }
    // Final l remains consistent with exit condition of original loop
}
