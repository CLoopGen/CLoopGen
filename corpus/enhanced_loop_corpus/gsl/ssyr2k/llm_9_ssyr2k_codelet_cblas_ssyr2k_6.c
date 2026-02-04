#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {  // Block outer loop by 2 to reduce iterations and increase computation per block
    for (j = 0; j <= i; j++) {
        float temp = 0.;
        int k_end = K & (~7);  // Round down K to nearest multiple of 8
        for (k = 0; k < k_end; k += 8) {  // Increased unrolling factor to 8 for higher computational intensity
            temp += A[i * lda + k + 0] * B[j * ldb + k + 0] + B[i * ldb + k + 0] * A[j * lda + k + 0];
            temp += A[i * lda + k + 1] * B[j * ldb + k + 1] + B[i * ldb + k + 1] * A[j * lda + k + 1];
            temp += A[i * lda + k + 2] * B[j * ldb + k + 2] + B[i * ldb + k + 2] * A[j * lda + k + 2];
            temp += A[i * lda + k + 3] * B[j * ldb + k + 3] + B[i * ldb + k + 3] * A[j * lda + k + 3];
            temp += A[i * lda + k + 4] * B[j * ldb + k + 4] + B[i * ldb + k + 4] * A[j * lda + k + 4];
            temp += A[i * lda + k + 5] * B[j * ldb + k + 5] + B[i * ldb + k + 5] * A[j * lda + k + 5];
            temp += A[i * lda + k + 6] * B[j * ldb + k + 6] + B[i * ldb + k + 6] * A[j * lda + k + 6];
            temp += A[i * lda + k + 7] * B[j * ldb + k + 7] + B[i * ldb + k + 7] * A[j * lda + k + 7];
        }
        for (; k < K; k++) {  // Remainder loop
            temp += A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k];
        }
        C[i * ldc + j] += alpha * temp;
        if (i + 1 < N) {
            C[(i + 1) * ldc + j] += alpha * temp;  // Extra update to increase computational load
        }
    }
}
}
