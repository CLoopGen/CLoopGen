#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with explicit pointer arithmetic and fixed increment
    // We traverse the matrix using a base pointer per row, advancing by strides
    // This variant uses direct pointer updates to emphasize strided access patterns

    float *base_C;
    int row_offset;

    for (i = 0; i < N; i++) {
        base_C = &C[ldc * i];  // Base pointer for row i
        row_offset = i;        // Start at diagonal element j = i
        for (j = i; j < N; j++) {
            *(base_C + j) *= beta;  // Strided write via pointer arithmetic
        }
    }
}
