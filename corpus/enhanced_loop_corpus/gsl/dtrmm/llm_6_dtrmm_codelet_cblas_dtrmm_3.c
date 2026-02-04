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
    double diag_A = nonunit ? A[i * lda + i] : 1.0;
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        double b_val = B[i * ldb + j];
        if (nonunit) {
            temp = diag_A * b_val;
        } else {
            temp = b_val;
        }
        for (k = i + 1; k < n1; k++) {
            temp += A[lda * k + i] * B[k * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
