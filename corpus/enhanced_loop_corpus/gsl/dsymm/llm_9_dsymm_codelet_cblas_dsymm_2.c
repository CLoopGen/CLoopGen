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
for (i = 0; i < n1; i += 2) {
    const int i1 = i + 1;
    for (j = 0; j < n2; j++) {
        double temp2_0 = 0., temp2_1 = 0.;
        const double temp1_0 = alpha * B[ldb * i + j];
        C[i * ldc + j] += temp1_0 * A[i * lda + i];
        if (i1 < n1) {
            const double temp1_1 = alpha * B[ldb * i1 + j];
            C[i1 * ldc + j] += temp1_1 * A[i1 * lda + i1];
            for (k = i1 + 1; k < n1; k++) {
                const double Aik0 = A[i * lda + k];
                const double Aik1 = A[i1 * lda + k];
                C[k * ldc + j] += Aik0 * temp1_0 + Aik1 * temp1_1;
                temp2_0 += Aik0 * B[ldb * k + j];
                temp2_1 += Aik1 * B[ldb * k + j];
            }
            C[i * ldc + j] += alpha * temp2_0;
            C[i1 * ldc + j] += alpha * temp2_1;
        } else {
            for (k = i + 1; k < n1; k++) {
                const double Aik = A[i * lda + k];
                C[k * ldc + j] += Aik * temp1_0;
                temp2_0 += Aik * B[ldb * k + j];
            }
            C[i * ldc + j] += alpha * temp2_0;
        }
    }
}
}
