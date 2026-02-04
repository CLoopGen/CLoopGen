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
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k += 2) {
    for (i = 0; i < N; i++) {
        float temp1_0 = alpha * A[k * lda + i];
        float temp2_0 = alpha * B[k * ldb + i];
        float temp1_1 = (k + 1 < K) ? alpha * A[(k + 1) * lda + i] : 0.0f;
        float temp2_1 = (k + 1 < K) ? alpha * B[(k + 1) * ldb + i] : 0.0f;
        for (j = 0; j <= i; j++) {
            C[i * lda + j] += temp1_0 * B[k * ldb + j] + temp2_0 * A[k * lda + j];
            if (k + 1 < K) {
                C[i * lda + j] += temp1_1 * B[(k + 1) * ldb + j] + temp2_1 * A[(k + 1) * lda + j];
            }
        }
    }
}
}
