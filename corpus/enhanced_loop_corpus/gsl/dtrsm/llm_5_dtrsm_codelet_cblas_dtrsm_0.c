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
    double Aii = nonunit ? A[lda * i + i] : 1.0;
    for (j = 0; j < n2; j++) {
        B[ldb * i + j] /= Aii;
    }
    for (k = 0; k < i; k++) {
        const double Aki = A[k * lda + i];
        if (Aki != 0.0) {
            for (j = 0; j < n2; j++) {
                B[ldb * k + j] -= Aki * B[ldb * i + j];
            }
        }
    }
}
}
