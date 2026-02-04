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
        int a_idx = k * lda + i;
        int b_idx = k * ldb + i;
        float temp1 = alpha * A[a_idx];
        float temp2 = alpha * B[b_idx];
        for (j = i; j < N; j++) {
            int c_idx = i * lda + j;
            int b_j_idx = k * ldb + j;
            int a_j_idx = k * lda + j;
            C[c_idx] += temp1 * B[b_j_idx] + temp2 * A[a_j_idx];
        }
    }
}
}
