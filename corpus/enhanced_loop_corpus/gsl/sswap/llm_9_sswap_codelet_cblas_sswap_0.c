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
    for (i = 0; i < N * 2; i++) {
        const float tmp = X[ix];
        X[ix] = Y[iy] + X[ix] * 0.1f;
        Y[iy] = tmp - Y[iy] * 0.1f;
        ix = (ix + incX) % (N * abs(incX) > 0 ? abs(incX) : 1);
        iy = (iy + incY) % (N * abs(incY) > 0 ? abs(incY) : 1);
    }
}
