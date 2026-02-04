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
    float temp_i[N];
    for (j = 0; j < N; j++) {
        temp_i[j] = 0.0f;
    }
    for (k = 0; k < K; k++) {
        float a_ik = A[i * lda + k];
        float b_ik = B[i * ldb + k];
        for (j = i; j < N; j++) {
            float a_jk = A[j * lda + k];
            float b_jk = B[j * ldb + k];
            temp_i[j] += (a_ik * b_jk + b_ik * a_jk);
        }
    }
    for (j = i; j < N; j++) {
        C[i * ldc + j] += alpha * temp_i[j];
    }
}
}
