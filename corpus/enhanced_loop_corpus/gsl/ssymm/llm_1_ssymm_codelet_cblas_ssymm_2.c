#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *B;
extern  int ldb;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (k = i; k < n1; k++) {
        const float alpha_Aik = (k == i) ? alpha * A[i * lda + i] : alpha * A[i * lda + k];
        for (j = 0; j < n2; j++) {
            const float temp1 = alpha * B[ldb * i + j];
            if (k == i) {
                C[i * ldc + j] += temp1 * A[i * lda + i];
            } else {
                C[k * ldc + j] += A[i * lda + k] * temp1;
            }
        }
    }
}
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp2 = 0.0f;
        for (k = i + 1; k < n1; k++) {
            temp2 += A[i * lda + k] * B[ldb * k + j];
        }
        C[i * ldc + j] += alpha * temp2;
    }
}
}
