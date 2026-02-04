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
    for (k = 0; k < i; k++) {
        const float Aik_scaled = A[i * lda + k] * alpha;
        for (j = 0; j < n2; j++) {
            const float temp1 = B[ldb * i + j];
            C[k * ldc + j] += A[i * lda + k] * temp1;
        }
        for (j = 0; j < n2; j++) {
            C[i * ldc + j] += Aik_scaled * B[ldb * k + j];
        }
    }
    for (j = 0; j < n2; j++) {
        const float temp1 = alpha * B[ldb * i + j];
        C[i * ldc + j] += temp1 * A[i * lda + i];
    }
}
}
