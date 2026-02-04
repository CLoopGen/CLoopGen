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
        const double temp1 = (i >= 0) ? alpha * B[ldb * i + j] : 0.0;
        double temp2 = 0.;
        for (k = 0; k < i; k++) {
            if (A[i * lda + k] != 0.0) {  // Skip zero elements for early pruning
                const double Aik = A[i * lda + k];
                C[k * ldc + j] += Aik * temp1;
                temp2 += Aik * B[ldb * k + j];
            }
        }
        if (temp2 > 0 || i == 0) {
            C[i * ldc + j] += temp1 * A[i * lda + i] + alpha * temp2;
        }
    }
}
}
