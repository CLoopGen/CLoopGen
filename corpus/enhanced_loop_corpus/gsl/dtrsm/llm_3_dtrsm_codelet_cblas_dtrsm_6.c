#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *A;
extern  int lda;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access via array flattening and index remapping (row-major simulation)
    ptrdiff_t idx;
    ptrdiff_t A_offset, B_offset_i, B_offset_k;
    for (i = n1; i > 0 && i--;) {
        A_offset = (ptrdiff_t)lda * i + i;
        B_offset_i = (ptrdiff_t)ldb * i;
        if (nonunit) {
            double Aii = A[A_offset];
            for (idx = 0; idx < n2; idx++) {
                B[B_offset_i + idx] /= Aii;
            }
        }
        for (k = 0; k < i; k++) {
            const double Aik = A[(ptrdiff_t)i * lda + k];
            B_offset_k = (ptrdiff_t)ldb * k;
            for (idx = 0; idx < n2; idx++) {
                B[B_offset_k + idx] -= Aik * B[B_offset_i + idx];
            }
        }
    }
}
