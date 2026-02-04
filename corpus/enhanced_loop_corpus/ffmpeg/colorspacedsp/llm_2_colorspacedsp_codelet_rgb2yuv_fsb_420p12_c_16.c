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
    // Instead of accessing elements consecutively, access every 2nd element in two passes to create strided access.
    // This modifies spatial locality and may affect cache performance.
    int stride = 2;
    for (x = 0; x < w; x += stride) {
        if (x + 1 < w) {
            rnd_scratch[0][0][x]     = rnd_scratch[0][1][x]     = rnd;
            rnd_scratch[0][0][x + 1] = rnd_scratch[0][1][x + 1] = rnd;
        } else {
            rnd_scratch[0][0][x] = rnd_scratch[0][1][x] = rnd;
        }
    }
}
