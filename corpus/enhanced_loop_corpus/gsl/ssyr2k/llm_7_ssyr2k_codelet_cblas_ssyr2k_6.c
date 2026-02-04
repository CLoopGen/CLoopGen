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
    float *temp_C = (float*)calloc(N * N, sizeof(float));
    if (!temp_C) return;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            float temp = 0.;
            for (k = 0; k < K; k++) {
                temp += (A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k]);
            }
            temp_C[i * N + j] = alpha * temp;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            C[i * ldc + j] += temp_C[i * N + j];
        }
    }
    free(temp_C);
}
