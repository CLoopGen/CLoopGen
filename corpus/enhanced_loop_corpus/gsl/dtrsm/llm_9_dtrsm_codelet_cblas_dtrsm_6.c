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
        for (j = 0; j < n2; j += 2) {
            if (j < n2) {
                B[ldb * i + j] /= Aii;
            }
            if (j + 1 < n2) {
                B[ldb * i + j + 1] /= Aii;
            }
        }
    }
    for (k = 0; k < i; k++) {
        const double Aik = A[i * lda + k];
        for (j = 0; j < n2; j++) {
            double temp = Aik * B[ldb * i + j];
            B[ldb * k + j] = B[ldb * k + j] - temp;
        }
    }
}
}
