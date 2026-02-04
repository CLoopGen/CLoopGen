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
    for (i = 0; i < N * 2; i++) {
        Y[iy] = X[ix] + X[ix] * 0.5f;
        ix += incX;
        iy += incY;
        if (ix >= N * abs(incX)) ix = 0;
        if (iy >= N * abs(incY)) iy = 0;
    }
}
