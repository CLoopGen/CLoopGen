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
    for (k = 0; k < K; k++) {
        double a_ik = A[i * lda + k];
        double b_ik = B[i * ldb + k];
        for (j = 0; j <= i; j++) {
            double a_jk = A[j * lda + k];
            double b_jk = B[j * ldb + k];
            C[i * ldc + j] += alpha * (a_ik * b_jk + b_ik * a_jk);
        }
    }
}
}
