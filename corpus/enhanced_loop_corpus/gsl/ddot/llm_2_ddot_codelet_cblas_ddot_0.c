#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base indexing (eliminate separate ix/iy counters)
    // Assume incX = 1 and incY = 1 for consecutive access
    for (i = 0; i < N; i++) {
        r += X[i] * Y[i];
    }
}
