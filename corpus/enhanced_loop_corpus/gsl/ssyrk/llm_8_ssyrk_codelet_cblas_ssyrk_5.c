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
    for (j = i; j < N; j += 2) {
        float temp1 = 0.;
        float temp2 = 0.;
        for (k = 0; k < K; k++) {
            temp1 += A[k * lda + i] * A[k * lda + j];
            if (j + 1 < N) {
                temp2 += A[k * lda + i] * A[k * lda + j + 1];
            }
        }
        C[i * ldc + j] += alpha * temp1;
        if (j + 1 < N) {
            C[i * ldc + j + 1] += alpha * temp2;
        }
    }
}
}
