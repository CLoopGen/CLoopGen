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
    for (k = i + 1; k < n1; k++) {
        for (j = 0; j < n2; j++) {
            double temp = 0.;
            if (nonunit && k == i + 1) {
                temp = A[i * lda + i] * B[i * ldb + j];
            } else if (k == i + 1) {
                temp = B[i * ldb + j];
            }
            temp += A[lda * k + i] * B[k * ldb + j];
            if (k == n1 - 1) {
                B[ldb * i + j] = alpha * temp;
            }
        }
    }
    if (n1 == i + 1) {
        for (j = 0; j < n2; j++) {
            if (n1 == 1) {
                double temp = nonunit ? A[0] * B[j] : B[j];
                B[j] = alpha * temp;
            }
        }
    }
}
}
