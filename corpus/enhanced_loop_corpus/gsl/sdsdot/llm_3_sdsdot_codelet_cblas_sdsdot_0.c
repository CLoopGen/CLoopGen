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
    // Variant 2: Strided memory access with reversed traversal
    // Access elements in reverse order with a fixed stride (e.g., every 2nd element)
    int stride = 2;
    int n_strided = (N + stride - 1) / stride;  // Number of elements to process with stride
    for (i = 0; i < n_strided; i++) {
        int idx = N - 1 - i * stride;  // Reverse strided index
        r += X[idx] * Y[idx];
    }
}
