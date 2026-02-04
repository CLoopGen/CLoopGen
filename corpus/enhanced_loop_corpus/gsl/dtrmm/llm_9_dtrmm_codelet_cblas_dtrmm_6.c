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
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j++) {
        if (i + 1 < n1) {
            double temp1 = 0., temp2 = 0.;
            if (nonunit) {
                temp1 = A[j * lda + j] * B[i * ldb + j];
                temp2 = A[j * lda + j] * B[(i + 1) * ldb + j];
            } else {
                temp1 = B[i * ldb + j];
                temp2 = B[(i + 1) * ldb + j];
            }
            for (k = j + 1; k < n2; k++) {
                double a_val = A[lda * k + j];
                temp1 += a_val * B[i * ldb + k];
                temp2 += a_val * B[(i + 1) * ldb + k];
            }
            B[ldb * i + j] = alpha * temp1;
            B[ldb * (i + 1) + j] = alpha * temp2;
        } else {
            double temp = nonunit ? A[j * lda + j] * B[i * ldb + j] : B[i * ldb + j];
            for (k = j + 1; k < n2; k++) {
                temp += A[lda * k + j] * B[i * ldb + k];
            }
            B[ldb * i + j] = alpha * temp;
        }
    }
}
}
