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
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j++) {
        float temp1 = 0., temp2 = 0.;
        if (nonunit && i < n1 - 1) {
            temp1 = A[i * lda + i] * B[i * ldb + j];
            temp2 = A[(i+1) * lda + (i+1)] * B[(i+1) * ldb + j];
        } else {
            temp1 = B[i * ldb + j];
            if (i + 1 < n1) temp2 = B[(i+1) * ldb + j];
        }
        for (k = i + 1; k < n1; k++) {
            temp1 += A[lda * i + k] * B[k * ldb + j];
            if (i + 1 < n1) {
                temp2 += A[lda * (i+1) + k] * B[k * ldb + j];
            }
        }
        B[ldb * i + j] = alpha * temp1;
        if (i + 1 < n1) {
            B[ldb * (i+1) + j] = alpha * temp2;
        }
    }
}
}
