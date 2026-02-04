#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
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
    double diag_val = nonunit ? A[i * lda + i] : 1.0;
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        // Introduce loop-carried dependency via reuse of B values from previous j iteration
        if (j > 0) {
            temp = B[i * ldb + j - 1]; // WAR dependence introduced: write after read
        }
        temp += diag_val * B[i * ldb + j];
        for (k = i + 1; k < n1; k++) {
            temp += A[lda * i + k] * B[k * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
