#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    for (j = 0; j <= i; j++) {
        float temp = 0.;
        for (k = 0; k < K - 3; k += 4) {
            temp += A[i * lda + k] * A[j * lda + k]
                  + A[i * lda + k + 1] * A[j * lda + k + 1]
                  + A[i * lda + k + 2] * A[j * lda + k + 2]
                  + A[i * lda + k + 3] * A[j * lda + k + 3];
        }
        for (; k < K; k++) {
            temp += A[i * lda + k] * A[j * lda + k];
        }
        C[i * ldc + j] += alpha * temp;
        if (i + 1 < N) {
            float temp2 = 0.;
            for (k = 0; k < K - 3; k += 4) {
                temp2 += A[(i + 1) * lda + k] * A[j * lda + k]
                       + A[(i + 1) * lda + k + 1] * A[j * lda + k + 1]
                       + A[(i + 1) * lda + k + 2] * A[j * lda + k + 2]
                       + A[(i + 1) * lda + k + 3] * A[j * lda + k + 3];
            }
            for (; k < K; k++) {
                temp2 += A[(i + 1) * lda + k] * A[j * lda + k];
            }
            C[(i + 1) * ldc + j] += alpha * temp2;
        }
    }
}
}
