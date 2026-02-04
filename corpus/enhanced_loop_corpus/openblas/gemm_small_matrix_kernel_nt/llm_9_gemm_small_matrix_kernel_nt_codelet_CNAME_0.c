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
    for (j = 0; j < N; j += 2) {
        float result_j1 = 0., result_j2 = 0.;
        for (k = 0; k < K; ++k) {
            result_j1 += A[i + k * lda] * B[k * ldb + j];
            if (j + 1 < N) {
                result_j2 += A[i + k * lda] * B[k * ldb + j + 1];
            }
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result_j1;
        if (j + 1 < N) {
            C[i + (j + 1) * ldc] = C[i + (j + 1) * ldc] * beta + alpha * result_j2;
        }
    }
}
}
