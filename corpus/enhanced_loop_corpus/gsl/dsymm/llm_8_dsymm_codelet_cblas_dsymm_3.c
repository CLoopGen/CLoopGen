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
        for (k = 0; k < i; k += 2) {
            const double Aik0 = A[i * lda + k];
            C[k * ldc + j] += Aik0 * temp1;
            temp2 += Aik0 * B[ldb * k + j];
            if (k + 1 < i) {
                const double Aik1 = A[i * lda + k + 1];
                C[(k + 1) * ldc + j] += Aik1 * temp1;
                temp2 += Aik1 * B[ldb * (k + 1) + j];
            }
        }
        C[i * ldc + j] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
