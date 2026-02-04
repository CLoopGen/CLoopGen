#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int *rnd_scratch[3][2];
extern int x;
extern  int rnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every 2nd element in two passes to create strided access.
    // This modifies spatial locality and may affect cache performance.
    int stride = 2;
    for (x = 0; x < w; x += stride) {
        if (x + 1 < w) {
            // Unroll by 2 with stride: update current and next index
            rnd_scratch[1][0][x]     = rnd;
            rnd_scratch[1][1][x]     = rnd;
            rnd_scratch[2][0][x]     = rnd;
            rnd_scratch[2][1][x]     = rnd;
            rnd_scratch[1][0][x + 1] = rnd;
            rnd_scratch[1][1][x + 1] = rnd;
            rnd_scratch[2][0][x + 1] = rnd;
            rnd_scratch[2][1][x + 1] = rnd;
        } else {
            // Handle odd-sized w
            rnd_scratch[1][0][x] = rnd_scratch[1][1][x] = rnd_scratch[2][0][x] = rnd_scratch[2][1][x] = rnd;
        }
    }
}
