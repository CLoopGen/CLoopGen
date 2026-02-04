#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Np;
extern double *t;
extern double increment;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // Processes even indices first, then odd indices in a second pass
    int stride = 2;
    for (i = 0; i < Np; i += stride) {
        t[i] = increment * (double)i;
    }
    for (i = 1; i < Np; i += stride) {
        t[i] = increment * (double)i;
    }
}
