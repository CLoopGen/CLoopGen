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
    // Variant 2: Reduced trip count with unrolled inner operations and conditional update to lower frequency of memory writes
    int step = 4;
    for (x = 0; x < w; x += step) {
        int base_val = rnd ^ 0xDEADBEEF;
        int shifted = base_val >> ((rnd ^ x) & 3);

        // Unroll and conditionally assign based on index parity
        if (x < w) {
            rnd_scratch[1][0][x] = shifted;
            rnd_scratch[2][0][x] = base_val;
        }
        if (x + 1 < w) {
            rnd_scratch[1][1][x+1] = base_val;
            rnd_scratch[2][1][x+1] = shifted;
        }
        if (x + 2 < w) {
            rnd_scratch[1][0][x+2] = shifted ^ 1;
        }
        if (x + 3 < w) {
            rnd_scratch[2][0][x+3] = base_val ^ 2;
        }
    }
}
