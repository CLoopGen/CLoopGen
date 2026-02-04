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
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        if (nonunit && A[i * lda + i] != 1.0) {
            temp = A[i * lda + i] * B[i * ldb + j];
        } else {
            temp = B[i * ldb + j];
        }
        for (k = i + 1; k < n1; k++) {
            double a_val = A[lda * k + i];
            if (a_val != 0.0) {
                temp += a_val * B[k * ldb + j];
            }
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
