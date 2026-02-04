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
for (i = 0; i < n1; i++) {
    ptrdiff_t offset_Aii = lda * i + i;
    ptrdiff_t offset_Bi = ldb * i;
    if (nonunit) {
        double Aii = A[offset_Aii];
        for (j = 0; j < n2; j++) {
            ptrdiff_t idx = offset_Bi + j;
            B[idx] /= Aii;
        }
    }
    for (k = i + 1; k < n1; k++) {
        ptrdiff_t offset_Aki = k * lda + i;
        ptrdiff_t offset_Bk = ldb * k;
        const double Aki = A[offset_Aki];
        for (j = 0; j < n2; j++) {
            ptrdiff_t idx_Bk = offset_Bk + j;
            ptrdiff_t idx_Bi = offset_Bi + j;
            B[idx_Bk] -= Aki * B[idx_Bi];
        }
    }
}
}
