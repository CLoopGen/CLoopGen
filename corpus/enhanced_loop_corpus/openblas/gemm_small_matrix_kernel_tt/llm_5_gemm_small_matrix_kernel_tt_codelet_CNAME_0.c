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
            if (A[i * lda + k] != 0.0 && B[k * ldb + j] != 0.0) {
                result += A[i * lda + k] * B[k * ldb + j];
            }
        }
        if (alpha != 0.0) {
            result *= alpha;
        } else {
            result = 0.0;
        }
        if (beta != 0.0) {
            C[i + j * ldc] = C[i + j * ldc] * beta + result;
        } else {
            C[i + j * ldc] = result;
        }
    }
}
}
