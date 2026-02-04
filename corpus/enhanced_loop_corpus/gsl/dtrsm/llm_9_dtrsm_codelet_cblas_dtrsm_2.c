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
for (i = 0; i < n1 && n2 > 0; i++) {
    if (nonunit) {
        double Aii = A[lda * i + i];
        B[ldb * i] /= Aii;
        for (j = 1; j < n2; j += 2) {
            double temp1 = B[ldb * i + j];
            double temp2 = (j + 1 < n2) ? B[ldb * i + j + 1] : 0.0;
            temp1 /= Aii;
            if (j + 1 < n2) temp2 /= Aii;
            B[ldb * i + j] = temp1;
            if (j + 1 < n2) B[ldb * i + j + 1] = temp2;
        }
    }
    for (k = i + 1; k < n1; k++) {
        const double Aik = A[i * lda + k];
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aik * B[ldb * i + j];
        }
    }
}
}
