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
    double local_sum = 0.0;
    int local_ix = 0;
    int local_iy = 0;
    for (i = 0; i < N; i++) {
        local_sum += X[local_ix] * Y[local_iy];
        local_ix += incX;
        local_iy += incY;
    }
    r += local_sum;
}
