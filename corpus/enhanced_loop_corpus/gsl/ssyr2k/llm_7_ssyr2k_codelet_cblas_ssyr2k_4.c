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
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp = 0.0f;
        int idx = i * lda + k;
        int idy = j * ldb + k;
        for (k = 0; k < K; k++) {
            float a_val = A[idx++];
            float b_val = B[idy++];
            temp += (a_val * B[i * ldb + k] * A[j * lda + k] + B[i * ldb + k] * a_val);
        }
        C[i * ldc + j] = alpha * temp + C[i * ldc + j];
    }
}
}
