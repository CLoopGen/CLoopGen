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
    double temp[n2];
    for (j = 0; j < n2; j++) {
        temp[j] = B[ldb * i + j];
    }
    for (k = 0; k < i; k++) {
        const double Aki = A[k * lda + i];
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aki * temp[j];
        }
    }
}
}
