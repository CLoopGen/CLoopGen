#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling the loop and accessing adjacent elements
    for (i = 1; i < 64; i += 4) {
        if (i + 0 < 64) x[i + 0] = -(unsigned int)x[i + 0];
        if (i + 2 < 64) x[i + 2] = -(unsigned int)x[i + 2];
    }
}
