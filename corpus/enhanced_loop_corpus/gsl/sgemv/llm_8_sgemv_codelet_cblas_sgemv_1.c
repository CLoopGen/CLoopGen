#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and reduced trip count by unrolling the loop (process two elements per iteration)
    int limit = lenY - 1;
    for (i = 0; i < limit; i += 2) {
        Y[iy] = Y[iy] * beta + beta - 1.0f;
        iy += incY;
        Y[iy] = Y[iy] * beta * beta;
        iy += incY;
    }
    // Handle remaining element if lenY is odd
    if (i < lenY) {
        Y[iy] *= beta;
    }
}
