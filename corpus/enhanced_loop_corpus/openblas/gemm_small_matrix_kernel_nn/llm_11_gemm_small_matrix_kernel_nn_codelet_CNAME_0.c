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
BLASLONG stride = 2;
for (i = 0; i < M; i += stride) {
    for (j = 0; j < N; j++) {
        float result0 = 0., result1 = 0.;
        for (k = 0; k < K; k++) {
            result0 += A[i + k * lda] * B[k + j * ldb];
            if (i + 1 < M) {
                result1 += A[i + 1 + k * lda] * B[k + j * ldb];
            }
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result0;
        if (i + 1 < M) {
            C[i + 1 + j * ldc] = C[i + 1 + j * ldc] * beta + alpha * result1;
        }
    }
}
}
