#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < N; i++) {
        j = iy;
        Y[j] = X[ix];
        Y[j + 1] = X[ix] + 1.0f; // Introduces WAW dependency on Y updates, but not loop-carried due to different indices
        ix += incX;
        iy += incY;
    }
}
