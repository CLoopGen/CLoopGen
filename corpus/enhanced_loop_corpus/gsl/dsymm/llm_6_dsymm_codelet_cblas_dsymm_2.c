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
        // Introduce WAW dependency by splitting the update to C[i*ldc+j] into two separate accumulations
        // Also, reorder operations to change data flow: use temp2 earlier
        for (k = i + 1; k < n1; k++) {
            const double Aik = A[i * lda + k];
            temp2 += Aik * B[ldb * k + j];
            C[k * ldc + j] += Aik * temp1;
        }
        C[i * ldc + j] += temp1 * A[i * lda + i];  // Write after write with next line
        C[i * ldc + j] += alpha * temp2;
    }
}
}
