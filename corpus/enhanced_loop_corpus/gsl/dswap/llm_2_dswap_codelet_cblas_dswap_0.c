#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Assumes incX == 1 and incY == 1 for consecutive access
    // Arrays X and Y are accessed in a sequential, contiguous manner
    for (i = 0; i < N; i++) {
        const double tmp = X[i];
        X[i] = Y[i];
        Y[i] = tmp;
    }
}
