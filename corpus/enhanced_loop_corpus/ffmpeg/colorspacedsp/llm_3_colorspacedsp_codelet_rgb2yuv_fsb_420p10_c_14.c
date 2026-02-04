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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the array from the end to the beginning (reverse order)
    for (x = w - 1; x >= 0; x--) {
        rnd_scratch[0][0][x] = rnd_scratch[0][1][x] = rnd;
    }
}
