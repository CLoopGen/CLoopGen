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
    // Variant 1: Consecutive memory access (unit stride)
    // Assume incX and incY are adjusted to 1 for consecutive access
    // Reset indices to start from 0
    int local_ix = 0;
    int local_iy = 0;
    for (i = 0; i < N; i++) {
        Y[local_iy] = X[local_ix];
        local_ix += 1;
        local_iy += 1;
    }
}
