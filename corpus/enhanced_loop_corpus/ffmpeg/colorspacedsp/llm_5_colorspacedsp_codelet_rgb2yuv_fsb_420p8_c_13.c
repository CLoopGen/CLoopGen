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
    for (x = 0; x < w; x++) {
        int val = rnd + x;
        if (val < 0) continue;
        rnd_scratch[1][0][x] = val;
        rnd_scratch[1][1][x] = val;
        rnd_scratch[2][0][x] = val;
        rnd_scratch[2][1][x] = val;
    }
}
