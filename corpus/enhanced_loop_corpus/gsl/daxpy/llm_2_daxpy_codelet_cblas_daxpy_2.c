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
    // Variant 1: Consecutive Memory Access (unit stride)
    // Assume incX = incY = 1 for consecutive access
    // Reset indices to start from 0
    ix = 0;
    iy = 0;
    for (i = 0; i < N; i++) {
        Y[iy] += alpha * X[ix];
        ix += 1;
        iy += 1;
    }
}
