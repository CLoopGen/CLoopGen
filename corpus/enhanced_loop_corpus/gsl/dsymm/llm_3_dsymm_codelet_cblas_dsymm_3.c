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
    double * restrict Ci = &C[i * ldc];        // Base pointer to row i of C
    double * restrict Bi = &B[i * ldb];        // Base pointer to row i of B
    for (j = 0; j < n2; j++) {
        const double temp1 = alpha * Bi[j];   // Consecutive access via base pointer
        double temp2 = 0.;
        for (k = 0; k < i; k++) {
            double * restrict Ak = &A[k * lda]; // Row k of A
            const double Aik = Ak[i];           // Strided access: A[k][i]
            Ci[k] += Aik * temp1;               // Write to C[i][k] using precomputed row
            temp2 += Aik * B[k * ldb + j];      // Indirect but regular access to B[k][j]
        }
        Ci[j] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
