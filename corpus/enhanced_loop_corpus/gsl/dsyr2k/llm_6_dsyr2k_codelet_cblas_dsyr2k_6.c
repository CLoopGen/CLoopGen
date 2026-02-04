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
    double temp_local = 0.0;
    for (j = 0; j <= i; j++) {
        temp_local = 0.0;
        for (k = 0; k < K; k++) {
            temp_local += A[i * lda + k] * B[j * ldb + k];
        }
        for (k = 0; k < K; k++) {
            temp_local += B[i * ldb + k] * A[j * lda + k];
        }
        C[i * ldc + j] += alpha * temp_local;
    }
}
}
