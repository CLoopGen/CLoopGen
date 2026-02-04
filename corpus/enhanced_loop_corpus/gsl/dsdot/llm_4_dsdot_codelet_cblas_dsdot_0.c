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
    if (N <= 0) return;
    for (i = 0; i < N; i++) {
        if (ix >= 0 && iy >= 0) {
            r += X[ix] * Y[iy];
        }
        ix += incX;
        iy += incY;
    }
}
