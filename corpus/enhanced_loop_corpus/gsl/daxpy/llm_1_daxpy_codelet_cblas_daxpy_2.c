#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N > 0) {
    for (i = 0; i < N; i += 2) {
        Y[iy] += alpha * X[ix];
        ix += incX;
        iy += incY;
        if (i + 1 < N) {
            Y[iy] += alpha * X[ix];
            ix += incX;
            iy += incY;
        }
    }
}
}
