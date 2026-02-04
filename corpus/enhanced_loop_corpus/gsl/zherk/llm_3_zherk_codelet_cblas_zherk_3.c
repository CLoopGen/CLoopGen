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
    // Variant 2: Strided memory access - traverse column-wise within the lower triangular part
    double *C_base = (double *)C;
    for (j = 0; j < N; j++) {
        for (i = j + 1; i < N; i++) {
            int idx = 2 * (ldc * i + j);
            C_base[idx] *= beta;
            C_base[idx + 1] *= beta;
        }
        // Handle diagonal element in a separate loop over i
        int diag_idx = 2 * (ldc * j + j);
        C_base[diag_idx] *= beta;
        C_base[diag_idx + 1] = 0;
    }
}
