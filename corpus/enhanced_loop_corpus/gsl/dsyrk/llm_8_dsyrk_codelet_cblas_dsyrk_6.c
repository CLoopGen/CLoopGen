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
    for (j = 0; j <= i; j += 2) {
        double temp1 = 0.;
        double temp2 = 0.;
        for (k = 0; k < K; k++) {
            temp1 += A[i * lda + k] * A[j * lda + k];
            if (j + 1 <= i) {
                temp2 += A[i * lda + k] * A[(j + 1) * lda + k];
            }
        }
        C[i * ldc + j] += alpha * temp1;
        if (j + 1 <= i) {
            C[i * ldc + (j + 1)] += alpha * temp2;
        }
    }
}
}
