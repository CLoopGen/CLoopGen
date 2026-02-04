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
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k += 2) {
    if (k + 1 < K) {
        for (i = 0; i < N; i++) {
            double temp1_0 = alpha * A[k * lda + i];
            double temp2_0 = alpha * B[k * ldb + i];
            double temp1_1 = alpha * A[(k+1) * lda + i];
            double temp2_1 = alpha * B[(k+1) * ldb + i];
            for (j = 0; j <= i; j++) {
                C[i * lda + j] += temp1_0 * B[k * ldb + j] + temp2_0 * A[k * lda + j];
                C[i * lda + j] += temp1_1 * B[(k+1) * ldb + j] + temp2_1 * A[(k+1) * lda + j];
            }
        }
    } else {
        for (i = 0; i < N; i++) {
            double temp1 = alpha * A[k * lda + i];
            double temp2 = alpha * B[k * ldb + i];
            for (j = 0; j <= i; j++) {
                C[i * lda + j] += temp1 * B[k * ldb + j] + temp2 * A[k * lda + j];
            }
        }
    }
}
}
