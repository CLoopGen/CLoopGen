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
    for (i = 0; i < N; i++) {
        if (ix >= 0 && iy >= 0) {
            const double tmp = X[ix];
            X[ix] = Y[iy];
            Y[iy] = tmp;
        }
        ix += incX;
        iy += incY;
    }
}
