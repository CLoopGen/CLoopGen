#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse column-wise with fixed stride, processing real and imaginary parts separately
    double *C_base = (double *)C;
    int stride = 2 * ldc;  // Stride between consecutive rows in flattened layout
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {  // Adjusted bounds to preserve lower triangle logic (i <= j)
            C_base[2 * (ldc * i + j)]     = 0.;
            C_base[2 * (ldc * i + j) + 1] = 0.;
        }
    }
}
