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
        const double temp1 = alpha * B[j * ldb + i];  // Transposed access: B[j][i] instead of B[i][j]
        double temp2 = 0.;
        C[i * ldc + j] += temp1 * A[i * lda + i];
        for (k = i + 1; k < n1; k++) {
            const double Aik = A[k * lda + i];  // Transposed access: A[k][i] instead of A[i][k]
            C[k * ldc + j] += Aik * temp1;
            temp2 += Aik * B[j * ldb + k];       // Transposed access: B[j][k] instead of B[k][j]
        }
        C[i * ldc + j] += alpha * temp2;
    }
}
}
