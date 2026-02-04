#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *B;
extern  int ldb;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp1 = 0.;
        float temp2 = 0.;
        for (k = 0; k < K; k += 2) {
            temp1 += (A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k]);
            if (k + 1 < K) {
                temp2 += (A[i * lda + k + 1] * B[j * ldb + k + 1] + B[i * ldb + k + 1] * A[j * lda + k + 1]);
            }
        }
        C[i * ldc + j] += alpha * (temp1 + temp2);
    }
}
}
