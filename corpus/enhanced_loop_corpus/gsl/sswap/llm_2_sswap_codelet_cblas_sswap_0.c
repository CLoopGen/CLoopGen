#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (assuming incX = incY = 1)
    // We remove the index variables ix and iy and use direct indexing with stride 1
    for (i = 0; i < N; i++) {
        const float tmp = X[i];
        X[i] = Y[i];
        Y[i] = tmp;
    }
}
