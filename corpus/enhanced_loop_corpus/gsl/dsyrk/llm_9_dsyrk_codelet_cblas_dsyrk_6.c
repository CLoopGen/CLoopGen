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
for (i = 0; i < N; i += 2) {
    for (j = 0; j <= i; j++) {
        double temp = 0.;
        for (k = 0; k < K - 1; k += 2) {
            temp += A[i * lda + k] * A[j * lda + k] +
                    A[i * lda + k + 1] * A[j * lda + k + 1];
        }
        if (K % 2 == 1) {
            temp += A[i * lda + K - 1] * A[j * lda + K - 1];
        }
        C[i * ldc + j] += alpha * temp;
        if (i + 1 < N) {
            double temp2 = 0.;
            for (k = 0; k < K - 1; k += 2) {
                temp2 += A[(i + 1) * lda + k] * A[j * lda + k] +
                         A[(i + 1) * lda + k + 1] * A[j * lda + k + 1];
            }
            if (K % 2 == 1) {
                temp2 += A[(i + 1) * lda + K - 1] * A[j * lda + K - 1];
            }
            C[(i + 1) * ldc + j] += alpha * temp2;
        }
    }
}
}
