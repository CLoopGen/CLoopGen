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
    // Variant 1: Strided memory access with step size of 2
    for (x = 0; x < w; x += 2) {
        rnd_scratch[0][0][x] = rnd_scratch[0][1][x] = rnd;
    }
    // Handle odd-sized w if necessary
    if (w % 2 == 1) {
        rnd_scratch[0][0][w-1] = rnd_scratch[0][1][w-1] = rnd;
    }
}
