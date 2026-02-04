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
        for (k = 0; k < i; k++) {
            const double Aik = A[k * lda + i];  // Access A transposed: A[k][i] instead of A[i][k]
            C[j * ldc + k] += Aik * temp1;      // Update C with transposed indexing: C[j][k]
            temp2 += Aik * B[j * ldb + k];      // B accessed as B[j][k], maintaining consistency
        }
        C[j * ldc + i] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
