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
        int temp = rnd + x; // Local computation with loop index
        rnd_scratch[0][0][x] = temp;
        rnd_scratch[0][1][w - 1 - x] = temp; // Introduces WAR/WAW hazard potential via reverse indexing; breaks strict loop-carried dependency on forward index
    }
}
