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
        result = 0.;
        for (k = 0; k < K; k++) {
            if (A[i + k * lda] != 0.0 && B[k + j * ldb] != 0.0) {
                result += A[i + k * lda] * B[k + j * ldb];
            }
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result;
    }
}
}
