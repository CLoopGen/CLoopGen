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
    // Variant 1: Strided memory access with stride of 2
    for (x = 0; x < w; x += 2) {
        if (x < w) {
            rnd_scratch[0][0][x] = rnd;
            rnd_scratch[0][1][x] = rnd;
        }
        int next = x + 1;
        if (next < w) {
            rnd_scratch[0][0][next] = rnd;
            rnd_scratch[0][1][next] = rnd;
        }
    }
}
