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
    int k1 = k;
    int k2 = k + 1;
    for (i = 0; i < N; i++) {
        float temp1a = alpha * A[k1 * lda + i];
        float temp2a = alpha * B[k1 * ldb + i];
        float temp1b = (k2 < K) ? alpha * A[k2 * lda + i] : 0.0f;
        float temp2b = (k2 < K) ? alpha * B[k2 * ldb + i] : 0.0f;
        for (j = i; j < N; j++) {
            C[i * lda + j] += temp1a * B[k1 * ldb + j] + temp2a * A[k1 * lda + j];
            if (k2 < K) {
                C[i * lda + j] += temp1b * B[k2 * ldb + j] + temp2b * A[k2 * lda + j];
            }
        }
    }
}
}
