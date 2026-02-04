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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    float *c_ptr = (float *)C;
    for (i = 0; i < N; i++) {
        int idx_diag = 2 * (ldc * i + i);
        *(c_ptr + idx_diag) *= beta;
        *(c_ptr + idx_diag + 1) = 0.0f;
        int base_row = ldc * i;
        for (j = i + 1; j < N; j++) {
            int idx = 2 * (base_row + j);
            *(c_ptr + idx) *= beta;
            *(c_ptr + idx + 1) *= beta;
        }
    }
}
