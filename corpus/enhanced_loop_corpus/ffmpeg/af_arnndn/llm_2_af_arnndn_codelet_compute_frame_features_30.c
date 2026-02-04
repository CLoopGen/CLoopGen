#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;
extern float *ceps_1;
extern float *ceps_2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    float *f = features;
    float *c0 = ceps_0;
    float *c1 = ceps_1;
    float *c2 = ceps_2;

    for (int i = 0; i < 6; i++) {
        *f++ = *c0 + *c1 + *c2;
        *(f + 21) = *c0 - *c2;
        *(f + 21 + 6) = *c0 - 2 * *c1 + *c2;
        c0++;
        c1++;
        c2++;
    }
}
