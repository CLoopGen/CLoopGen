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
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        float temp = 0.;
        for (k = 0; k < K - 3; k += 4) {
            temp += A[k * lda + i] * A[k * lda + j]
                  + A[(k+1) * lda + i] * A[(k+1) * lda + j]
                  + A[(k+2) * lda + i] * A[(k+2) * lda + j]
                  + A[(k+3) * lda + i] * A[(k+3) * lda + j];
        }
        // Handle remaining k values
        for (; k < K; k++) {
            temp += A[k * lda + i] * A[k * lda + j];
        }
        C[i * ldc + j] += alpha * temp;
        if (i + 1 < N && j >= i + 1) {
            float temp2 = 0.;
            for (k = 0; k < K; k++) {
                temp2 += A[k * lda + i + 1] * A[k * lda + j];
            }
            C[(i + 1) * ldc + j] += alpha * temp2;
        }
    }
}
}
