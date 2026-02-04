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
    double B_cache[n2];
    for (j = 0; j < n2; j++) {
        B_cache[j] = B[ldb * i + j];
    }
    for (j = 0; j < n2; j++) {
        if (nonunit) {
            double Ajj = A[lda * j + j];
            B_cache[j] /= Ajj;
        }
        for (k = j + 1; k < n2; k++) {
            B_cache[k] -= A[k * lda + j] * B_cache[j];
        }
    }
    for (j = 0; j < n2; j++) {
        B[ldb * i + j] = B_cache[j];
    }
}
}
