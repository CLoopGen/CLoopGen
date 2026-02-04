#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N / 2; i++) {
        r += X[ix] * Y[iy];
        r += X[ix + incX] * Y[iy + incY];
        ix += 2 * incX;
        iy += 2 * incY;
    }
    if (N % 2 == 1) {
        r += X[ix] * Y[iy];
    }
}
