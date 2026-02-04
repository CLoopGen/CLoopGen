#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening indices
    // Instead of using bx and by as separate dimensions, we traverse in a linear fashion
    // assuming row-major order for the first two dimensions [bx][by]
    int idx = 0;
    for (int i = 0; i < 16; i++) {
        int bx = i % 4;
        int by = i / 4;
        all_mv[bx][by][0][0][0][0] = pmv[0];
        all_mv[bx][by][0][0][0][1] = pmv[1];
    }
}
