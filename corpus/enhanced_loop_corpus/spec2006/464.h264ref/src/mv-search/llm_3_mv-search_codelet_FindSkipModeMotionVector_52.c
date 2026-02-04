#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access — iterate with a stride of 2, then handle remainder
    // This creates non-unit stride in both bx and by dimensions
    int by_step, bx_step;
    // First pass: strided access with step size 2
    for (by_step = 0; by_step < 4; by_step += 2)
        for (bx_step = 0; bx_step < 4; bx_step += 2) {
            all_mv[bx_step][by_step][0][0][0][0] = 0;
            all_mv[bx_step][by_step][0][0][0][1] = 0;
        }
    // Second pass: fill in the remaining elements not covered by the stride
    for (by = 0; by < 4; by++)
        for (bx = 0; bx < 4; bx++) {
            if ((bx % 2 != 0) || (by % 2 != 0)) { // Skip those already set
                all_mv[bx][by][0][0][0][0] = 0;
                all_mv[bx][by][0][0][0][1] = 0;
            }
        }
}
