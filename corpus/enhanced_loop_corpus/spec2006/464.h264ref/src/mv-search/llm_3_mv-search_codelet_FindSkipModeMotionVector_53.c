#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    // Traverse bx and by in reverse order with step size 2 to create strided access pattern
    for (by = 3; by >= 0; by -= 2) {
        for (bx = 3; bx >= 0; bx -= 2) {
            all_mv[bx][by][0][0][0][0] = pmv[0];
            all_mv[bx][by][0][0][0][1] = pmv[1];
        }
    }
    // Fill in the skipped elements with forward small steps to ensure all are covered
    for (by = 1; by < 4; by += 2) {
        for (bx = 1; bx < 4; bx += 2) {
            all_mv[bx][by][0][0][0][0] = pmv[0];
            all_mv[bx][by][0][0][0][1] = pmv[1];
        }
    }
}
