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
    for (i = 0; i < N; i++) {
        double temp1 = alpha * A[k * lda + i];
        double temp2 = alpha * B[k * ldb + i];
        double* c_row = &C[i * lda];
        const double* a_row_k = &A[k * lda];
        const double* b_row_k = &B[k * ldb];
        for (j = 0; j <= i; j++) {
            double b_val = b_row_k[j];
            double a_val = a_row_k[j];
            c_row[j] += temp1 * b_val + temp2 * a_val;
        }
    }
}
}
