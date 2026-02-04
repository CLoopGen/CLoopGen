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
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            double temp_i = 0., temp_ip1 = 0.;
            if (nonunit) {
                temp_i = A[i * lda + i] * B[i * ldb + j];
                temp_ip1 = A[(i+1) * lda + (i+1)] * B[(i+1) * ldb + j];
            } else {
                temp_i = B[i * ldb + j];
                temp_ip1 = B[(i+1) * ldb + j];
            }
            for (k = i + 1; k < n1; k++) {
                temp_i += A[lda * i + k] * B[k * ldb + j];
                temp_ip1 += A[lda * (i+1) + k] * B[k * ldb + j];
            }
            B[ldb * i + j] = alpha * temp_i;
            B[ldb * (i+1) + j] = alpha * temp_ip1;
        }
    } else {
        for (j = 0; j < n2; j++) {
            double temp = 0.;
            if (nonunit) {
                temp = A[i * lda + i] * B[i * ldb + j];
            } else {
                temp = B[i * ldb + j];
            }
            for (k = i + 1; k < n1; k++) {
                temp += A[lda * i + k] * B[k * ldb + j];
            }
            B[ldb * i + j] = alpha * temp;
        }
    }
}
}
