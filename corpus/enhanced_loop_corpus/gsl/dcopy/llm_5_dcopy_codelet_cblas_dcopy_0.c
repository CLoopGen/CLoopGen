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
    for (i = 0; i < N; i++) {
        Y[iy] = X[ix];
        ix += incX;
        iy += incY;
        if (i == N / 2) {
            Y[iy] = 0.0;
            iy += incY;
            i++;
        }
    }
}
