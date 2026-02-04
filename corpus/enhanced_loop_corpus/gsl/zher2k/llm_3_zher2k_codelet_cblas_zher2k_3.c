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
    // Variant 2: Strided memory access with fixed column stride, simulating a transposed-like pattern
    double *C_base = (double *)C;
    for (j = 0; j < N; j++) {
        for (i = j + 1; i < N; i++) {
            int offset = 2 * (ldc * i + j);
            C_base[offset] *= beta;
            C_base[offset + 1] *= beta;
        }
        // Handle diagonal element in original row-major order
        int diag_offset = 2 * (ldc * j + j);
        C_base[diag_offset] *= beta;
        C_base[diag_offset + 1] = 0.;
    }
}
