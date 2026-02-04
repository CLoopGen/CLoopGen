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
    int y;
    for (x = 0; x < w; x++) {
        for (y = 1; y <= 2; y++) {
            rnd_scratch[y][0][x] = rnd * (y - 0); 
            rnd_scratch[y][1][x] = rnd * (y - 0); 
        }
    }
}
