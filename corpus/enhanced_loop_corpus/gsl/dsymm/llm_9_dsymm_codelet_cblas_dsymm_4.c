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
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            const double temp1_i0 = alpha * B[ldb * i + j];
            const double temp1_i1 = alpha * B[ldb * (i+1) + j];
            double temp2_i0 = 0.;
            double temp2_i1 = 0.;
            C[i * ldc + j] += temp1_i0 * A[j * lda + j];
            C[(i+1) * ldc + j] += temp1_i1 * A[j * lda + j];
            for (k = j + 1; k < n2; k++) {
                const double Ajk = A[j * lda + k];
                C[i * ldc + k] += temp1_i0 * Ajk;
                C[(i+1) * ldc + k] += temp1_i1 * Ajk;
                temp2_i0 += B[ldb * i + k] * Ajk;
                temp2_i1 += B[ldb * (i+1) + k] * Ajk;
            }
            C[i * ldc + j] += alpha * temp2_i0;
            C[(i+1) * ldc + j] += alpha * temp2_i1;
        }
    } else {
        for (j = 0; j < n2; j++) {
            const double temp1 = alpha * B[ldb * i + j];
            double temp2 = 0.;
            C[i * ldc + j] += temp1 * A[j * lda + j];
            for (k = j + 1; k < n2; k++) {
                const double Ajk = A[j * lda + k];
                C[i * ldc + k] += temp1 * Ajk;
                temp2 += B[ldb * i + k] * Ajk;
            }
            C[i * ldc + j] += alpha * temp2;
        }
    }
}
}
