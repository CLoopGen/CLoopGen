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
    for (i = 0; i < N; i++) {
        double temp1_k0 = alpha * A[k * lda + i];
        double temp2_k0 = alpha * B[k * ldb + i];
        double temp1_k1 = (k+1 < K) ? alpha * A[(k+1) * lda + i] : 0.0;
        double temp2_k1 = (k+1 < K) ? alpha * B[(k+1) * ldb + i] : 0.0;
        for (j = i; j < N; j++) {
            C[i * lda + j] += temp1_k0 * B[k * ldb + j] + temp2_k0 * A[k * lda + j];
            if (k+1 < K) {
                C[i * lda + j] += temp1_k1 * B[(k+1) * ldb + j] + temp2_k1 * A[(k+1) * lda + j];
            }
        }
    }
}
}
