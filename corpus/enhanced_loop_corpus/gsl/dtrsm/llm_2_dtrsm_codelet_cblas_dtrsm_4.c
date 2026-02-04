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
    if (nonunit) {
        double Aii = A[lda * i + i];
        for (j = 0; j < n2; j += 2) {
            if (j + 1 < n2) {
                B[ldb * i + j] /= Aii;
                B[ldb * i + j + 1] /= Aii;
            } else {
                B[ldb * i + j] /= Aii;
            }
        }
    }
    for (k = i + 1; k < n1; k++) {
        const double Aki = A[k * lda + i];
        for (j = 0; j < n2; j += 2) {
            if (j + 1 < n2) {
                B[ldb * k + j] -= Aki * B[ldb * i + j];
                B[ldb * k + j + 1] -= Aki * B[ldb * i + j + 1];
            } else {
                B[ldb * k + j] -= Aki * B[ldb * i + j];
            }
        }
    }
}
}
