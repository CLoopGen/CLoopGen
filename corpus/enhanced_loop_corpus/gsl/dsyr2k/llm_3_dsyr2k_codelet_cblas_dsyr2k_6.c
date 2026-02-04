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
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        double temp = 0.;
        for (k = 0; k < K; k++) {
            int a_idx1 = i * lda + k;
            int b_idx1 = j * ldb + k;
            int b_idx2 = i * ldb + k;
            int a_idx2 = j * lda + k;
            temp += (A[a_idx1] * B[b_idx1] + B[b_idx2] * A[a_idx2]);
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
