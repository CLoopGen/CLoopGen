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
// Initialize C with beta scaling first (separate compute phase)
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        C[i + j * ldc] *= beta;
    }
}
// Then perform GEMM-like accumulation with modified access: traverse B by columns, A by rows
for (k = 0; k < K; k++) {
    for (j = 0; j < N; j++) {
        float b_val = B[k + j * ldb];  // One element of B per inner loop
        for (i = 0; i < M; i++) {
            // A accessed with increasing i => unit stride (good locality)
            // C updated with unit stride
            C[i + j * ldc] += alpha * A[i + k * lda] * b_val;
        }
    }
}
}
