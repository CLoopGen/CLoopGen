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
    // Instead of accessing elements sequentially, access every 2nd element in two passes (stride of 2)
    int stride = 2;
    for (x = 0; x < w; x += stride) {
        if (x + 0 < w) {
            rnd_scratch[1][0][x + 0] = rnd_scratch[1][1][x + 0] = 
            rnd_scratch[2][0][x + 0] = rnd_scratch[2][1][x + 0] = rnd;
        }
        if (x + 1 < w) {
            rnd_scratch[1][0][x + 1] = rnd_scratch[1][1][x + 1] = 
            rnd_scratch[2][0][x + 1] = rnd_scratch[2][1][x + 1] = rnd;
        }
    }
}
