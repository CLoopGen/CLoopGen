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
for (i = n1; i > 0 && i--;) {
    if (nonunit) {
        double Aii = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii;
        }
    }
    for (k = 0; k < i; k += 2) {
        const double Aik0 = A[i * lda + k];
        const double Aik1 = (k + 1 < i) ? A[i * lda + k + 1] : 0.0;
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aik0 * B[ldb * i + j];
            if (k + 1 < i) {
                B[ldb * (k + 1) + j] -= Aik1 * B[ldb * i + j];
            }
        }
    }
}
}
