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
    for (j = 0; j <= i; j++) {
        float temp1 = 0., temp2 = 0.;
        for (k = 0; k < K; k++) {
            temp1 += A[k * lda + i] * A[k * lda + j];
            if (i + 1 < N) {
                temp2 += A[k * lda + (i+1)] * A[k * lda + j];
            }
        }
        C[i * ldc + j] += alpha * temp1;
        if (i + 1 < N) {
            C[(i+1) * ldc + j] += alpha * temp2;
        }
    }
}
}
