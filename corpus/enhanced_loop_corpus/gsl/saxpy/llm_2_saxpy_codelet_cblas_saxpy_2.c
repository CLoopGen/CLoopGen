#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (assume incX = incY = 1)
    // Reset indices to start from 0 for consecutive access
    ix = 0;
    iy = 0;
    for (i = 0; i < N; i++) {
        Y[iy] += alpha * X[ix];
        ix++;
        iy++;
    }
}
