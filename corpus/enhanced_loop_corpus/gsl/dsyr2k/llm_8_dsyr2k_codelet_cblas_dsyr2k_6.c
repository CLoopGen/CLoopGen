#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *B;
extern  int ldb;
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
        for (k = 0; k < K - 1; k += 2) {
            temp1 += (A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k]);
            temp2 += (A[i * lda + k + 1] * B[j * ldb + k + 1] + B[i * ldb + k + 1] * A[j * lda + k + 1]);
        }
        if (K % 2 == 1) {
            temp1 += (A[i * lda + K - 1] * B[j * ldb + K - 1] + B[i * lda + K - 1] * A[j * lda + K - 1]);
        }
        C[i * ldc + j] += alpha * (temp1 + temp2);
        if (j + 1 <= i && j + 1 < N) {
            double temp = 0.;
            for (k = 0; k < K; k++) {
                temp += (A[i * lda + k] * B[(j+1) * ldb + k] + B[i * ldb + k] * A[(j+1) * lda + k]);
            }
            C[i * ldc + (j+1)] += alpha * temp;
        }
    }
}
}
