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
    for (j = 0; j < n2; j++) {
        if (i >= n1) continue;
        const double temp1 = alpha * B[ldb * i + j];
        double temp2 = 0.;
        for (k = 0; k < j && k < 4; k++) {
            const double Ajk = A[j * lda + k];
            C[i * ldc + k] += temp1 * Ajk;
            temp2 += B[ldb * i + k] * Ajk;
        }
        for (; k < j; k++) {
            const double Ajk = A[j * lda + k];
            temp2 += B[ldb * i + k] * Ajk;
        }
        C[i * ldc + j] += temp1 * A[j * lda + j] + alpha * temp2;
        if (i + 1 < n1) {
            const double temp1_next = alpha * B[ldb * (i + 1) + j];
            double temp2_next = 0.;
            for (k = 0; k < j; k++) {
                const double Ajk = A[j * lda + k];
                C[(i + 1) * ldc + k] += temp1_next * Ajk;
                temp2_next += B[ldb * (i + 1) + k] * Ajk;
            }
            C[(i + 1) * ldc + j] += temp1_next * A[j * lda + j] + alpha * temp2_next;
        }
    }
}
}
