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
        float temp1 = 0.;
        float temp2 = 0.;
        for (k = 0; k < K; k++) {
            temp1 += A[i * lda + k] * A[j * lda + k];
            if (i + 1 < N) {
                temp2 += A[(i + 1) * lda + k] * A[j * lda + k];
            }
        }
        C[i * ldc + j] += alpha * temp1;
        if (i + 1 < N) {
            C[(i + 1) * ldc + j] += alpha * temp2;
        }
    }
}
}
