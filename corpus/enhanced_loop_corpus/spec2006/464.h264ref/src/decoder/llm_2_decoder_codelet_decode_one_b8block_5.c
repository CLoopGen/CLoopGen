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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (by, then bx), access with a stride by iterating over a linear index
    // and computing 2D indices with non-unit stride simulation (e.g., block-wise or transposed-like pattern)
    int total_elements = (by1 - by0) * (bx1 - bx0);
    for (int idx = 0; idx < total_elements; idx++) {
        int by_idx = by0 + (idx / (bx1 - bx0));  // row
        int bx_idx = bx0 + (idx % (bx1 - bx0));  // column
        mv[0][by_idx][bx_idx] = mv[1][by_idx][bx_idx] = 0;
    }
}
