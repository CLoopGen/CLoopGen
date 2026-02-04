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
for (i = n1; i > 0 && i--;) {
    for (j = 0; j < n2; j += 2) {
        float temp1 = 0., temp2 = 0.;
        for (k = 0; k < i - (i % 2); k += 2) {
            temp1 += A[lda * i + k] * B[k * ldb + j];
            temp2 += A[lda * i + k + 1] * B[(k + 1) * ldb + j];
            if (j + 1 < n2) {
                temp1 += A[lda * i + k] * B[k * ldb + j + 1];
                temp2 += A[lda * i + k + 1] * B[(k + 1) * ldb + j + 1];
            }
        }
        for (; k < i; k++) {
            temp1 += A[lda * i + k] * B[k * ldb + j];
            if (j + 1 < n2) {
                temp2 += A[lda * i + k] * B[k * ldb + j + 1];
            }
        }
        if (nonunit) {
            temp1 += A[i * lda + i] * B[i * ldb + j];
            if (j + 1 < n2) {
                temp2 += A[i * lda + i] * B[i * ldb + j + 1];
            }
        } else {
            temp1 += B[i * ldb + j];
            if (j + 1 < n2) {
                temp2 += B[i * ldb + j + 1];
            }
        }
        B[ldb * i + j] = alpha * temp1;
        if (j + 1 < n2) {
            B[ldb * i + j + 1] = alpha * temp2;
        }
    }
}
}
