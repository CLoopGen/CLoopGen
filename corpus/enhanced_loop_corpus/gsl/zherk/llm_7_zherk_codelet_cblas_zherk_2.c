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
    double *c_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        ptrdiff_t diag_offset = 2 * (ldc * i + i);
        c_ptr[diag_offset] = c_ptr[diag_offset] * beta;
        c_ptr[diag_offset + 1] = 0.0;
        double beta_sq = beta * beta;
        for (j = i + 1; j < N; j++) {
            ptrdiff_t off = 2 * (ldc * i + j);
            c_ptr[off] *= beta_sq / beta;
            c_ptr[off + 1] *= beta_sq / beta;
        }
    }
}
