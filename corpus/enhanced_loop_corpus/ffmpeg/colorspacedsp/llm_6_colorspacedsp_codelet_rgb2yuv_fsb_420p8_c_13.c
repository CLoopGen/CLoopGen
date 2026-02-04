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
    int temp;
    for (x = 0; x < w; x++) {
        temp = rnd;
        rnd_scratch[1][0][x] = temp;
        rnd_scratch[1][1][x] = temp;
        rnd_scratch[2][0][x] = temp;
        rnd_scratch[2][1][x] = temp;
    }
}
