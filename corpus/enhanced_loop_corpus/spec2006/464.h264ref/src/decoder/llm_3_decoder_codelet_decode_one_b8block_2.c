#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern int mv[2][4][4];
extern int bx0;
extern int bx1;
extern int by0;
extern int by1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive linearized access using flattened indexing to improve cache performance
    // Treat the [4][4] subarray as a linear block of 16 elements, zeroing sequentially
    int offset;
    for (offset = 0; offset < 16; offset++) {
        int by_idx = (offset >> 2) + by0;  // equivalent to offset / 4
        int bx_idx = (offset & 3) + bx0;   // equivalent to offset % 4
        // Only process indices within the specified range
        if (by_idx >= by0 && by_idx < by1 && bx_idx >= bx0 && bx_idx < bx1) {
            mv[0][by_idx][bx_idx] = 0;
            mv[1][by_idx][bx_idx] = 0;
        }
    }
}
