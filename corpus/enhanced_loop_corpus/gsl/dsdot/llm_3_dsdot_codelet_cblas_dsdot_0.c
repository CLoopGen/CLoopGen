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
    // Variant 2: Strided access with fixed stride (unrolled-like pattern, stride of 2)
    int stride = 2;
    int n_strided = N / stride;
    int remainder = N % stride;
    // Main strided loop
    for (i = 0; i < n_strided; i++) {
        r += X[ix] * Y[iy];
        r += X[ix + incX] * Y[iy + incY];
        ix += 2 * incX;
        iy += 2 * incY;
    }
    // Handle remainder
    for (; i < N; i++) {
        r += X[ix] * Y[iy];
        ix += incX;
        iy += incY;
    }
}
