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
ptrdiff_t offset_A, offset_B_i, offset_B_k;
for (i = 0; i < n1; i++) {
    offset_B_i = (ptrdiff_t)i * ldb;
    if (nonunit) {
        offset_A = (ptrdiff_t)i * lda + i;
        double Aii = A[offset_A];
        for (j = 0; j < n2; j++) {
            B[offset_B_i + j] /= Aii;
        }
    }
    for (k = i + 1; k < n1; k++) {
        offset_A = (ptrdiff_t)i * lda + k;
        const double Aik = A[offset_A];
        offset_B_k = (ptrdiff_t)k * ldb;
        for (j = 0; j < n2; j++) {
            B[offset_B_k + j] -= Aik * B[offset_B_i + j];
        }
    }
}
}
