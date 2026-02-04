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
        const double Aki1 = A[k * lda + i];
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aki1 * B[ldb * i + j];
        }
        if (k + 1 < i) {
            const double Aki2 = A[(k + 1) * lda + i];
            for (j = 0; j < n2; j++) {
                B[ldb * (k + 1) + j] -= Aki2 * B[ldb * i + j];
            }
        }
    }
}
}
