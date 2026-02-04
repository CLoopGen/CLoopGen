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
    for (j = 0; j <= i; j++) {
        float temp = 0.;
        int k = 0;
        for (; k < K - 3; k += 4) {
            temp += A[i * lda + k] * A[j * lda + k] +
                    A[i * lda + k+1] * A[j * lda + k+1] +
                    A[i * lda + k+2] * A[j * lda + k+2] +
                    A[i * lda + k+3] * A[j * lda + k+3];
        }
        for (; k < K; k++) {
            temp += A[i * lda + k] * A[j * lda + k];
        }
        if (temp > 0.0f || alpha != 0.0f) {
            C[i * ldc + j] += alpha * temp;
        }
    }
}
}
