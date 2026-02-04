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
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            float temp_val = alpha * (A[k * lda + i] * B[k * ldb + j] + B[k * ldb + i] * A[k * lda + j]);
            C[i * lda + j] += temp_val;
        }
    }
}
}
