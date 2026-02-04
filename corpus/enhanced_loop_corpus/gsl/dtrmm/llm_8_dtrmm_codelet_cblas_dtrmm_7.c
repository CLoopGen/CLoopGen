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
    for (j = n2 - 1; j >= 0; j--) {
        double temp1 = 0.0, temp2 = 0.0;
        int k;
        // Unroll the inner loop by a factor of 2 to increase arithmetic operations per iteration
        for (k = 0; k + 1 < j; k += 2) {
            temp1 += A[lda * j + k] * B[i * ldb + k];
            temp2 += A[lda * j + k + 1] * B[i * ldb + k + 1];
        }
        // Handle remaining element if j is odd
        if (k < j) {
            temp1 += A[lda * j + k] * B[i * ldb + k];
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
