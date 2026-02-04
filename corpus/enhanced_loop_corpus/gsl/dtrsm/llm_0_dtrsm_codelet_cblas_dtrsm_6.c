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
        j = 0;
        do {
            B[ldb * i + j] /= Aii;
            j++;
        } while (j < n2);
    }
    for (k = 0; k < i; k++) {
        const double Aik = A[i * lda + k];
        j = 0;
        do {
            B[ldb * k + j] -= Aik * B[ldb * i + j];
            j++;
        } while (j < n2);
    }
}
}
