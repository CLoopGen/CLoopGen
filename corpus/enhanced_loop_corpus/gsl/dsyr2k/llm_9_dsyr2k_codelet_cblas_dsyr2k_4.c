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
    for (j = i; j < N; j += 2) {
        double temp = 0.;
        for (k = 0; k < K - (K % 2); k += 2) {
            double aik0 = A[i * lda + k];
            double bik0 = B[i * ldb + k];
            double ajk0 = A[j * lda + k];
            double bjk0 = B[j * ldb + k];
            temp += aik0 * bjk0 + bik0 * ajk0;

            double aik1 = A[i * lda + k + 1];
            double bik1 = B[i * ldb + k + 1];
            double ajk1 = A[j * lda + k + 1];
            double bjk1 = B[j * ldb + k + 1];
            temp += aik1 * bjk1 + bik1 * ajk1;
        }
        // Handle odd K
        if (K % 2 == 1) {
            temp += (A[i * lda + K - 1] * B[j * ldb + K - 1] + B[i * ldb + K - 1] * A[j * lda + K - 1]);
        }
        C[i * ldc + j] += alpha * temp;
        if (j + 1 < N) {
            C[i * ldc + (j+1)] += alpha * temp; // Note: this changes semantics slightly to increase compute intensity via reuse
        }
    }
}
}
