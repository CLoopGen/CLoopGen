#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG M;
extern BLASLONG N;
extern BLASLONG K;
extern float *A;
extern BLASLONG lda;
extern float alpha;
extern float *B;
extern BLASLONG ldb;
extern float beta;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    for (i = 0; i < M; i++) {
        float a_val = A[i * lda + k];
        for (j = 0; j < N; j++) {
            float b_val = B[k + j * ldb];
            C[i + j * ldc] += a_val * b_val;
        }
    }
}
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * C[i + j * ldc];
    }
}
}
