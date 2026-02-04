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
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i += 2) {
        float temp1a = alpha * A[k * lda + i];
        float temp2a = alpha * B[k * ldb + i];
        float temp1b = (i+1 < N) ? alpha * A[k * lda + i + 1] : 0.0f;
        float temp2b = (i+1 < N) ? alpha * B[k * ldb + i + 1] : 0.0f;
        for (j = i; j < N; j++) {
            C[i * lda + j] += temp1a * B[k * ldb + j] + temp2a * A[k * lda + j];
            if (i+1 < N) {
                C[(i+1) * lda + j] += temp1b * B[k * ldb + j] + temp2b * A[k * lda + j];
            }
        }
    }
}
}
