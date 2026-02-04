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
        float tempA[256]; // Local block to enable consecutive access if K <= 256
        for (k = 0; k < K; k++) {
            tempA[k] = A[i + k * lda]; // Strided read from A, now stored consecutively
        }
        for (k = 0; k < K; k++) {
            result += tempA[k] * B[k * ldb + j]; // B still accessed with stride
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result;
    }
}
}
