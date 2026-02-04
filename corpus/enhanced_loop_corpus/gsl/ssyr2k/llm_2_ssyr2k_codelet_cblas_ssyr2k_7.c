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
        float temp1 = alpha * A[i * lda + k];
        float temp2 = alpha * B[i * ldb + k];
        for (j = 0; j <= i; j++) {
            C[i * lda + j] += temp1 * B[j * ldb + k] + temp2 * A[j * lda + k];
        }
    }
}
}
