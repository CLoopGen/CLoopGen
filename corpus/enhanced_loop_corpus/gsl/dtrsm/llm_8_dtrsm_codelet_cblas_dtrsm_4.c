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
for (i = 0; i < n1; i += 2) {
    if (nonunit && (i + 1 < n1)) {
        double Aii0 = A[lda * i + i];
        double Aii1 = A[lda * (i+1) + (i+1)];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii0;
            B[ldb * (i+1) + j] /= Aii1;
        }
    } else if (nonunit) {
        double Aii = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii;
        }
    }
    for (k = i + 1; k < n1; k++) {
        const double Aki = A[k * lda + i];
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aki * B[ldb * i + j];
        }
    }
}
}
