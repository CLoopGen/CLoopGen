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
    double *local_Y = Y;
    int local_iy = iy;
    int local_ix = ix;
    int step = incX;
    double a = alpha;
    for (i = 0; i < N; i++) {
        Y[local_iy] += a * X[local_ix];
        local_ix += step;
        local_iy += incY;
    }
}
