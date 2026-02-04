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
    for (j = n2; j > 0; j--) {
        double temp1 = 0.0, temp2 = 0.0;
        int k = 0;
        for (; k + 1 < j; k += 2) {
            temp1 += A[lda * k + j] * B[i * ldb + k];
            temp2 += A[lda * (k+1) + j] * B[i * ldb + (k+1)];
        }
        for (; k < j; k++) {
            temp1 += A[lda * k + j] * B[i * ldb + k];
        }
        double temp = temp1 + temp2;
        if (nonunit) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
