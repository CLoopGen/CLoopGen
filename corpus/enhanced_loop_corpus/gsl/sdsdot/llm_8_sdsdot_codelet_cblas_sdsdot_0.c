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
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            r += X[ix] * Y[iy] + X[ix + incX] * Y[iy + incY];
            ix += 2 * incX;
            iy += 2 * incY;
        } else {
            r += X[ix] * Y[iy];
            ix += incX;
            iy += incY;
        }
    }
}
