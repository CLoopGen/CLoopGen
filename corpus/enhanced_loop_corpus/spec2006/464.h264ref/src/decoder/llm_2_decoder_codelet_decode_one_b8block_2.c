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
    // Variant 1: Strided memory access with increased stride for temporal locality reduction
    // Access pattern: Instead of row-major order, traverse with a fixed stride of 2, handling remainder separately
    int stride = 2;
    for (by = by0; by < by1; by++) {
        for (bx = bx0; bx < bx1; bx += stride) {
            // Ensure we don't go out of bounds in inner dimension
            if (bx + 1 < bx1) {
                mv[0][by][bx]     = 0;
                mv[1][by][bx]     = 0;
                mv[0][by][bx + 1] = 0;
                mv[1][by][bx + 1] = 0;
            } else {
                mv[0][by][bx] = 0;
                mv[1][by][bx] = 0;
            }
        }
    }
}
