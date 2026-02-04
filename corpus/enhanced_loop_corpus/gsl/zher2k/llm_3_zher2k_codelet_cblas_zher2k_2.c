#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with precomputed row stride
    double *c_base = (double *)C;
    int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        double *row_start = c_base + 2 * i;
        row_start[i * stride / 2] *= beta;  // Diagonal real part
        row_start[i * stride / 2 + 1] = 0.0;  // Diagonal imaginary part set to zero
        for (j = i + 1; j < N; j++) {
            int offset = j * stride / 2;
            row_start[offset] *= beta;
            row_start[offset + 1] *= beta;
        }
    }
}
