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
    if (N > 0) {
        int outer = N / 2;
        int remainder = N % 2;
        for (i = 0; i < outer; i++) {
            r += X[ix] * Y[iy];
            ix += incX;
            iy += incY;
            r += X[ix] * Y[iy];
            ix += incX;
            iy += incY;
        }
        for (i = 0; i < remainder; i++) {
            r += X[ix] * Y[iy];
            ix += incX;
            iy += incY;
        }
    }
}
