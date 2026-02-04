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
        int temp = rnd + x; // Introduce local computation dependent on loop index
        rnd_scratch[0][0][x] = temp;
        rnd_scratch[0][1][x] = temp;
        rnd = temp; // Introduce WAW and loop-carried dependency: each iteration overwrites rnd used in next
    }
}
