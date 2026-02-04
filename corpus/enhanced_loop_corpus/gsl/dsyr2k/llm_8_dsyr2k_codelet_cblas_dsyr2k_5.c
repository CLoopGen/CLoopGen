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
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i += 2) {
        double temp1_0 = alpha * A[k * lda + i];
        double temp2_0 = alpha * B[k * ldb + i];
        double temp1_1 = (i+1 < N) ? alpha * A[k * lda + i + 1] : 0.0;
        double temp2_1 = (i+1 < N) ? alpha * B[k * ldb + i + 1] : 0.0;
        for (j = i; j < N; j++) {
            C[i * lda + j] += temp1_0 * B[k * ldb + j] + temp2_0 * A[k * lda + j];
            if (i+1 < N) {
                C[(i+1) * lda + j] += temp1_1 * B[k * ldb + j] + temp2_1 * A[k * lda + j];
            }
        }
    }
}
}
