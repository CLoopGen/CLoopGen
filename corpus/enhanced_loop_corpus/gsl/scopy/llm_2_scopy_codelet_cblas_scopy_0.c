#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Assuming incX and incY are positive strides, we rewrite the loop to access X and Y consecutively
    // by precomputing base pointers and using unit stride in the loop.
    float *baseX = &X[ix];
    float *baseY = &Y[iy];
    int stepX = incX;
    int stepY = incY;
    for (i = 0; i < N; i++) {
        baseY[i] = baseX[i * stepX];
    }
}
