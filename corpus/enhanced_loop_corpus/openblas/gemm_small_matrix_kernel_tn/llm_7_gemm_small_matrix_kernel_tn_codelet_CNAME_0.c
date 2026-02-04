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
float *local_C = (float*)__builtin_alloca(N * sizeof(float)); // Local buffer to restructure data access
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        local_C[j] = 0.0; // Initialize local accumulator to break dependency on prior C values
    }
    for (k = 0; k < K; k++) {
        for (j = 0; j < N; j++) {
            local_C[j] += A[i * lda + k] * B[k + j * ldb]; // Reorder loops: k outer, j inner; eliminate reduction dependency in k
        }
    }
    for (j = 0; j < N; j++) {
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * local_C[j]; // Final update with no loop-carried dependence on result
    }
}
}
