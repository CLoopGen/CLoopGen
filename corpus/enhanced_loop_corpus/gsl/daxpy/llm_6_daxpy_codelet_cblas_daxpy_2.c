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
    double temp = 0.0;
    for (i = 0; i < N; i++) {
        temp = alpha * X[ix];
        Y[iy] += temp;
        ix += incX;
        iy += incY;
    }
}
