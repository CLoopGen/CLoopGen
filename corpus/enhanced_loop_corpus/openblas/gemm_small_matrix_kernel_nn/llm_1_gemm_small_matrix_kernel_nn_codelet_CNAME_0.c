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
for (j = 0; j < N; j++) {
    for (i = 0; i < M; i++) {
        C[i + j * ldc] *= beta;
    }
    for (k = 0; k < K; k++) {
        for (i = 0; i < M; i++) {
            C[i + j * ldc] += alpha * A[i + k * lda] * B[k + j * ldb];
        }
    }
}
}
