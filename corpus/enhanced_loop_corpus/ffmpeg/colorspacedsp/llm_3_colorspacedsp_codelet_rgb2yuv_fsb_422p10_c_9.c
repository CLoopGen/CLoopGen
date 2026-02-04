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
    // Variant 2: Strided memory access with stride of 2 (process even indices first, then odd)
    int i;
    // First pass: even indices
    for (i = 0; i < w; i += 2) {
        rnd_scratch[1][0][i] = rnd_scratch[1][1][i] = rnd_scratch[2][0][i] = rnd_scratch[2][1][i] = rnd;
    }
    // Second pass: odd indices
    for (i = 1; i < w; i += 2) {
        rnd_scratch[1][0][i] = rnd_scratch[1][1][i] = rnd_scratch[2][0][i] = rnd_scratch[2][1][i] = rnd;
    }
}
