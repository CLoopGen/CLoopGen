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
for (i = 0; i < M; i += 2) {
    for (j = 0; j < N; j++) {
        float result1 = 0., result2 = 0.;
        BLASLONG k;
        for (k = 0; k < K; k++) {
            result1 += A[i * lda + k] * B[k + j * ldb];
            if (i + 1 < M) {
                result2 += A[(i+1) * lda + k] * B[k + j * ldb];
            }
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result1;
        if (i + 1 < M) {
            C[(i+1) + j * ldc] = C[(i+1) + j * ldc] * beta + alpha * result2;
        }
    }
}
}
