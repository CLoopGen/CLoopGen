#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        const double tmp1 = X[ix];
        X[ix] = Y[iy];
        Y[iy] = tmp1;
        ix += incX;

        if (i + 1 < N) {
            const double tmp2 = X[ix + incX];
            X[ix + incX] = Y[iy + incY];
            Y[iy + incY] = tmp2;
        }

        iy += incY;
        if (i + 1 < N) {
            ix += incX;
            iy += incY;
        }
    }
}
