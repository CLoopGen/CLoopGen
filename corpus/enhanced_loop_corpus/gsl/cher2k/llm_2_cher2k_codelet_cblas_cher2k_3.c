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
    // Variant 1: Consecutive memory access by precomputing base pointer and using linear indexing
    float *C_ptr = (float *)C;
    for (int i = 0; i < N; i++) {
        int base_idx = 2 * ldc * i;
        for (int j = 0; j < i; j++) {
            int offset = base_idx + 2 * j;
            C_ptr[offset] *= beta;
            C_ptr[offset + 1] *= beta;
        }
        int diag_offset = base_idx + 2 * i;
        C_ptr[diag_offset] *= beta;
        C_ptr[diag_offset + 1] = 0.0f;
    }
}
