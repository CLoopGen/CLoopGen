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
        float temp_a[K];
        float temp_b[K];
        for (k = 0; k < K; k++) {
            temp_a[k] = A[i * lda + k];
            temp_b[k] = B[k + j * ldb];
        }
        for (k = 0; k < K; k++) {
            result += temp_a[k] * temp_b[k];
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result;
    }
}
}
