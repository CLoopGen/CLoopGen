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
    for (k = 0; k < K; k++) {
        float b_val = B[k * ldb + j];
        for (i = 0; i < M; i++) {
            // Reorder loops: j-k-i, accumulate into C using consecutive write pattern per column
            // Access A with unit stride now: i varies fastest, so A[i + k*lda] becomes consecutive
            if (k == 0) {
                C[i + j * ldc] *= beta; // Apply beta once before accumulation
            }
            C[i + j * ldc] += alpha * A[i + k * lda] * b_val;
        }
    }
}
}
