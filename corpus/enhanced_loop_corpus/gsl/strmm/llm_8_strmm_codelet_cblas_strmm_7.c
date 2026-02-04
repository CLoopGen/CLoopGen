#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *B;
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
    for (j = n2; j > 0 && j--;) {
        float temp1 = 0.0, temp2 = 0.0;
        int k_unroll;
        for (k = 0; k + 1 < j; k += 2) {
            temp1 += A[lda * j + k] * B[i * ldb + k];
            temp2 += A[lda * j + k + 1] * B[i * ldb + k + 1];
        }
        float temp = temp1 + temp2;
        if (k < j) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
