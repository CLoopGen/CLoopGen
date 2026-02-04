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
    for (j = i; j < N; j++) {
        double temp = 0.;
        const double* a_base = &A[i * lda];
        const double* b_base = &B[j * ldb];
        const double* b_base_i = &B[i * ldb];
        const double* a_base_j = &A[j * lda];
        for (k = 0; k < K; k++) {
            temp += (a_base[k] * b_base[k] + b_base_i[k] * a_base_j[k]);
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
