#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i && j < K; j++) {
        float temp = 0.;
        int k_bound = (K > 16) ? K - (K % 4) : K; // Align to multiple of 4 if large enough
        for (k = 0; k < k_bound; k += 4) {
            temp += A[k * lda + i] * A[k * lda + j]
                  + A[(k+1) * lda + i] * A[(k+1) * lda + j]
                  + A[(k+2) * lda + i] * A[(k+2) * lda + j]
                  + A[(k+3) * lda + i] * A[(k+3) * lda + j];
        }
        // Handle remainder
        for (; k < K; k++) {
            temp += A[k * lda + i] * A[k * lda + j];
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
