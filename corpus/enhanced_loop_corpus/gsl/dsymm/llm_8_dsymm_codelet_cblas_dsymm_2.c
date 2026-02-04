#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        const double temp1 = alpha * B[ldb * i + j];
        double temp2 = 0.;
        C[i * ldc + j] += temp1 * A[i * lda + i];
        for (k = i + 2; k < n1; k += 2) {
            const double Aik0 = A[i * lda + k];
            const double Aik1 = A[i * lda + k + 1];
            C[k * ldc + j] += Aik0 * temp1;
            C[(k + 1) * ldc + j] += Aik1 * temp1;
            temp2 += Aik0 * B[ldb * k + j] + Aik1 * B[ldb * (k + 1) + j];
        }
        if (k == n1 - 1) {
            const double Aik = A[i * lda + k];
            C[k * ldc + j] += Aik * temp1;
            temp2 += Aik * B[ldb * k + j];
        }
        C[i * ldc + j] += alpha * temp2;
    }
}
}
