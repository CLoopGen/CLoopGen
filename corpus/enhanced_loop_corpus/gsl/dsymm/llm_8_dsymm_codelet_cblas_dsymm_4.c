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
    for (j = 0; j < n2; j += 2) {
        const double temp1a = alpha * B[ldb * i + j];
        double temp2a = 0.;
        C[i * ldc + j] += temp1a * A[j * lda + j];
        for (k = j + 1; k < n2; k++) {
            const double Ajk = A[j * lda + k];
            C[i * ldc + k] += temp1a * Ajk;
            temp2a += B[ldb * i + k] * Ajk;
        }
        C[i * ldc + j] += alpha * temp2a;

        if (j + 1 < n2) {
            const double temp1b = alpha * B[ldb * i + j + 1];
            double temp2b = 0.;
            C[i * ldc + j + 1] += temp1b * A[(j+1) * lda + j + 1];
            for (k = j + 2; k < n2; k++) {
                const double Ajk = A[(j+1) * lda + k];
                C[i * ldc + k] += temp1b * Ajk;
                temp2b += B[ldb * i + k] * Ajk;
            }
            C[i * ldc + j + 1] += alpha * temp2b;
        }
    }
}
}
