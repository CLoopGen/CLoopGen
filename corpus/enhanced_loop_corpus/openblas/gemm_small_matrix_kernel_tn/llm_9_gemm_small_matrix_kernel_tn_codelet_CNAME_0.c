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
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        float sum = 0.0;
        BLASLONG k;
        for (k = 0; k < K - (K % 4); k += 4) {
            sum += A[i * lda + k] * B[k + j * ldb]
                 + A[i * lda + k+1] * B[k+1 + j * ldb]
                 + A[i * lda + k+2] * B[k+2 + j * ldb]
                 + A[i * lda + k+3] * B[k+3 + j * ldb];
        }
        for (; k < K; k++) {
            sum += A[i * lda + k] * B[k + j * ldb];
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * sum;
    }
}
}
