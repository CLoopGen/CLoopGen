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
float *C_temp = (float*)__builtin_alloca(N * sizeof(float));
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        float sum = 0.0f;
        for (k = 0; k < K; k++) {
            sum += A[i * lda + k] * B[k * ldb + j];
        }
        C_temp[j] = alpha * sum;
    }
    for (j = 0; j < N; j++) {
        C[i + j * ldc] = C[i + j * ldc] * beta + C_temp[j];
    }
}
}
