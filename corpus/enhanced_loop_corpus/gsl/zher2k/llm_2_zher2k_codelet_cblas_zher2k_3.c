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
    // Variant 1: Consecutive memory access by precomputing base pointer and using linear index
    double *C_ptr = (double *)C;
    int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        int base_idx_i = stride * i;
        for (j = 0; j < i; j++) {
            int idx = base_idx_i + 2 * j;
            C_ptr[idx] *= beta;
            C_ptr[idx + 1] *= beta;
        }
        int diag_idx = base_idx_i + 2 * i;
        C_ptr[diag_idx] *= beta;
        C_ptr[diag_idx + 1] = 0.;
    }
}
