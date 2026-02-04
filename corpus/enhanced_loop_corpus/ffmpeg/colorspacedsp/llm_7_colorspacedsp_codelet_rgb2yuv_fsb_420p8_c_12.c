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
    int temp = rnd;
    for (x = 0; x < w; x++) {
        if (x > 0) {
            temp = rnd_scratch[0][0][x-1]; // Introduce loop-carried dependence (RAW)
        }
        rnd_scratch[0][0][x] = temp;
        rnd_scratch[0][1][x] = temp ^ rnd;
    }
}
