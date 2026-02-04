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
    // Variant 1: Strided Memory Access (access every 2nd element in two passes)
    for (x = 0; x < w; x += 2) {
        rnd_scratch[1][0][x] = rnd_scratch[1][1][x] = rnd_scratch[2][0][x] = rnd_scratch[2][1][x] = rnd;
    }
    for (x = 1; x < w; x += 2) {
        rnd_scratch[1][0][x] = rnd_scratch[1][1][x] = rnd_scratch[2][0][x] = rnd_scratch[2][1][x] = rnd;
    }
}
