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
    // Variant 1: Introduce loop-carried dependence (WAW and RAW) by making current iteration depend on previous iteration
    // This creates a loop-carried dependency along 'by': each iteration depends on the prior value of mv[0][by-1][bx]
    if (by0 < by1 && bx0 < bx1) {
        // Initialize base case to avoid undefined behavior
        for (bx = bx0; bx < bx1; bx++) {
            mv[0][by0][bx] = mv[1][by0][bx] = 0;
        }
        for (by = by0 + 1; by < by1; by++) {
            for (bx = bx0; bx < bx1; bx++) {
                // Introduce RAW and WAW dependence: current value used to compute next
                mv[0][by][bx] = mv[0][by-1][bx] + 1;  // Loop-carried dependence (RAW)
                mv[1][by][bx] = 0;
            }
        }
    }
}
