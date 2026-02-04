#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N && j < i + 4; j++) {
        double temp = 0.;
        for (k = 0; k < K - (K % 4); k += 4) {
            temp += A[k * lda + i] * A[k * lda + j]
                  + A[(k+1) * lda + i] * A[(k+1) * lda + j]
                  + A[(k+2) * lda + i] * A[(k+2) * lda + j]
                  + A[(k+3) * lda + i] * A[(k+3) * lda + j];
        }
        for (; k < K; k++) {
            temp += A[k * lda + i] * A[k * lda + j];
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
