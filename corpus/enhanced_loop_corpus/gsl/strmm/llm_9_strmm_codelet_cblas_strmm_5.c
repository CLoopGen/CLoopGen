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
        float temp1 = 0.0f, temp2 = 0.0f;
        if (nonunit && i < n1) {
            temp1 = A[j * lda + j] * B[i * ldb + j];
        } else if (i < n1) {
            temp1 = B[i * ldb + j];
        }
        if (nonunit && (i + 1) < n1) {
            temp2 = A[j * lda + j] * B[(i + 1) * ldb + j];
        } else if ((i + 1) < n1) {
            temp2 = B[(i + 1) * ldb + j];
        }
        for (k = j + 1; k < n2; k++) {
            if (i < n1) temp1 += A[lda * j + k] * B[i * ldb + k];
            if ((i + 1) < n1) temp2 += A[lda * j + k] * B[(i + 1) * ldb + k];
        }
        if (i < n1) B[ldb * i + j] = alpha * temp1;
        if ((i + 1) < n1) B[ldb * (i + 1) + j] = alpha * temp2;
    }
}
}
