#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern double r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (assuming incX = 1, incY = 1)
    // We remove index variables and use direct array indexing with loop counter
    for (i = 0; i < N; i++) {
        r += X[i] * Y[i];
    }
}
