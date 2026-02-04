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
        // Access A with consecutive prefetching along k, but A is accessed with stride lda
        // Change access order to improve spatial locality by blocking or restructuring
        for (k = 0; k < K; k += 2) {
            // Unroll loop and access two elements at once to promote vectorization and reduce strided access overhead
            if (k + 1 < K) {
                result += A[i + k * lda] * B[k + j * ldb] + A[i + (k+1) * lda] * B[(k+1) + j * ldb];
            } else {
                result += A[i + k * lda] * B[k + j * ldb];
            }
        }
        C[i + j * ldc] = C[i + j * ldc] * beta + alpha * result;
    }
}
}
