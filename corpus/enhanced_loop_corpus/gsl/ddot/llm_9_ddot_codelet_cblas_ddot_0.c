#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1 = 0.0, temp2 = 0.0;
    int halfN = N / 2;
    for (i = 0; i < halfN; i++) {
        temp1 += X[ix] * Y[iy];
        ix += incX;
        iy += incY;
    }
    for (i = 0; i < halfN; i++) {
        temp2 += X[ix] * Y[iy];
        ix += incX;
        iy += incY;
    }
    r += temp1 + temp2;
}
