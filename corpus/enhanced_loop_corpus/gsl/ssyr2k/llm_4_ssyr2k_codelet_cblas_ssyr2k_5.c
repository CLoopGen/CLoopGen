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
    for (i = 0; i < N; i++) {
        float temp1 = alpha * A[k * lda + i];
        float temp2 = alpha * B[k * ldb + i];
        if (temp1 != 0.0f || temp2 != 0.0f) {
            for (j = i; j < N; j++) {
                C[i * lda + j] += temp1 * B[k * ldb + j] + temp2 * A[k * lda + j];
            }
        }
    }
}
}
