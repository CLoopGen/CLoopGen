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
    // and reduced trip count by unrolling the loop (processing 2 iterations per loop cycle)
    for (i = 0; i < lenY; i += 2) {
        Y[iy] = Y[iy] * beta + beta - 1.0f;
        iy += incY;
        if (i + 1 < lenY) {
            Y[iy] = Y[iy] * beta + beta - 1.0f;
            iy += incY;
        }
    }
}
