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
    for (j = 0; j <= i; j++) {
        double temp = 0.;
        const double *a_ptr = &A[i * lda];
        const double *b_ptr = &B[j * ldb];
        const double *b_base = &B[i * ldb];
        const double *a_base = &A[j * lda];
        for (k = 0; k < K; k++) {
            temp += (a_ptr[k] * b_ptr[k] + b_base[k] * a_base[k]);
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
