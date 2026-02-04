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
for (k = 0; k < K; k++) {
    for (i = 0; i < M; i++) {
        float a_ik = A[i + k * lda]; // Hoist invariant load out of inner loop, introduce dependency on k first
        for (j = 0; j < N; j++) {
            C[i + j * ldc] += a_ik * B[k + j * ldb] * alpha; // Accumulate directly into C with alpha scaled
        }
    }
}
// Apply beta scaling in a separate loop to break combined update and eliminate loop-carried dependency on previous C values during accumulation
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        C[i + j * ldc] *= beta;
    }
}
}
