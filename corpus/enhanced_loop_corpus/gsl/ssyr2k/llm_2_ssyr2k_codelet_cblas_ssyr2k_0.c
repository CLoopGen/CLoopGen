#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of row-major (j increasing consecutively), access with a fixed stride across rows
    int stride = ldc;
    for (i = 0; i < N * ldc; i += stride) {
        for (j = i / ldc; j < N; j++) {
            C[i + j] = 0.;
        }
    }
}
