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
float *c_base = C;
for (j = 0; j < N; j++) {
    float *b_col = &B[j];
    for (i = 0; i < M; i++) {
        result = 0.0f;
        for (k = 0; k < K; k++) {
            result += A[i * lda + k] * b_col[k * ldb];
        }
        c_base[i + j * ldc] = c_base[i + j * ldc] * beta + alpha * result;
    }
}
}
