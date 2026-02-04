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
    for (k = 0; k < n2; k++) {
        for (j = 0; j <= k; j++) {
            double temp = 0.;
            if (nonunit && j == k) {
                temp = A[j * lda + j] * B[i * ldb + j];
            } else if (j == k) {
                temp = B[i * ldb + j];
            }
            if (j < k) {
                temp += A[lda * k + j] * B[i * ldb + k];
                B[ldb * i + j] = alpha * temp;
            } else if (j == k) {
                for (int m = j + 1; m < n2; m++) {
                    temp += A[lda * m + j] * B[i * ldb + m];
                }
                B[ldb * i + j] = alpha * temp;
            }
        }
    }
}
}
