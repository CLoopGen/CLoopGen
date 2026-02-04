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
    for (j = 0; j < n2; j += 2) {
        double temp1 = 0., temp2 = 0.;
        if (nonunit) {
            temp1 = A[i * lda + i] * B[i * ldb + j];
            if (j + 1 < n2) {
                temp2 = A[i * lda + i] * B[i * ldb + j + 1];
            }
        } else {
            temp1 = B[i * ldb + j];
            if (j + 1 < n2) {
                temp2 = B[i * ldb + j + 1];
            }
        }
        for (k = i + 1; k < n1; k++) {
            temp1 += A[lda * i + k] * B[k * ldb + j];
            if (j + 1 < n2) {
                temp2 += A[lda * i + k] * B[k * ldb + j + 1];
            }
        }
        B[ldb * i + j] = alpha * temp1;
        if (j + 1 < n2) {
            B[ldb * i + j + 1] = alpha * temp2;
        }
    }
}
}
