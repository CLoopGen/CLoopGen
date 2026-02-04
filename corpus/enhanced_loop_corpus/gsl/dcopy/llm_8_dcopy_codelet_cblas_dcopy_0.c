#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        Y[iy] = X[ix];
        ix += incX * 2;
        iy += incY * 2;
        if (i + 1 < N) {
            Y[iy - incY * 2 + incY] = X[ix - incX * 2 + incX];
        }
    }
}
