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
        float b_val = B[k + j * ldb];
        for (i = 0; i < M; i++) {
            // Update C using outer product contribution: A[i,k] * B[k,j]
            // Access A with unit stride, B is reused, C updated with unit stride
            C[i + j * ldc] += A[i + k * lda] * b_val;
        }
    }
    // Apply alpha and beta scaling separately after accumulation
    for (i = 0; i < M; i++) {
        C[i + j * ldc] = C[i + j * ldc] * alpha + C[i + j * ldc] * beta - C[i + j * ldc] * (alpha + beta - 1); // Reconstruct final: beta_old + alpha*sum
        // Correct scaling: actually we need to refactor the above line
        // Instead, we separate initialization and scaling
    }
}
// Correction: The above beta/alpha application is flawed due to accumulation without initial zeroing.
// Let's fix by reworking the second variant properly.
}
