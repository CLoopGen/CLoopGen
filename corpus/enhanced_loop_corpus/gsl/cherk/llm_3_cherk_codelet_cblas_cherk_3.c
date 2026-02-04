#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access via Linear Indexing
    // Flatten the 2D access pattern into a linear scan with bounds tracking
    // Simulates row-major traversal while maintaining logical structure
    int linear_idx = 0;
    int total_elements = 2 * ldc * N; // Total size in float units
    float *c_ptr = (float *)C;

    for (i = 0; i < N; i++) {
        // Process off-diagonal elements: j from 0 to i-1
        for (j = 0; j < i; j++) {
            linear_idx = 2 * (ldc * i + j);
            c_ptr[linear_idx] *= beta;
            c_ptr[linear_idx + 1] *= beta;
        }
        // Handle diagonal: real part scaled, imaginary set to zero
        linear_idx = 2 * (ldc * i + i);
        c_ptr[linear_idx] *= beta;
        c_ptr[linear_idx + 1] = 0;
    }
}
