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
    // Variant 1: Consecutive memory access with loop unrolling by 2
    int i;
    for (i = 0; i < w - 1; i += 2) {
        rnd_scratch[1][0][i]     = rnd_scratch[1][1][i]     = rnd;
        rnd_scratch[2][0][i]     = rnd_scratch[2][1][i]     = rnd;
        rnd_scratch[1][0][i + 1] = rnd_scratch[1][1][i + 1] = rnd;
        rnd_scratch[2][0][i + 1] = rnd_scratch[2][1][i + 1] = rnd;
    }
    // Handle remaining element if w is odd
    if (i < w) {
        rnd_scratch[1][0][i] = rnd_scratch[1][1][i] = rnd_scratch[2][0][i] = rnd_scratch[2][1][i] = rnd;
    }
}
