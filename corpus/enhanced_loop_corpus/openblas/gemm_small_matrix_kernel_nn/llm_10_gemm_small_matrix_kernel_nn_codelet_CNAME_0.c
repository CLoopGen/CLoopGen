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
        k = 0;
        if (K % 2 == 1) {
            result += A[i + k * lda] * B[k + j * ldb];
            k++;
        }
        for (; k < K; k += 2) {
            result += A[i + k * lda] * B[k + j * ldb] + A[i + (k+1) * lda] * B[(k+1) + j * ldb];
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result;
    }
}
}
