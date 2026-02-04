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
    double temp_scalar = A[i * lda + i]; // Hoist invariant component to break some RAW dependencies
    for (j = 0; j < n2; j++) {
        const double temp1 = alpha * B[ldb * i + j];
        double temp2 = 0.;
        // Eliminate loop-carried dependence on C by using a local accumulator before final write
        double c_update = temp1 * temp_scalar; // Use hoisted value
        for (k = i + 1; k < n1; k++) {
            const double Aik = A[i * lda + k];
            // Reorder computation: accumulate temp2 first to change dependency chain
            temp2 += Aik * B[ldb * k + j];
            // Maintain independent updates to C: no WAR due to unique k,j indices
            C[k * ldc + j] += Aik * temp1;
        }
        c_update += alpha * temp2;
        C[i * ldc + j] += c_update; // Single write to C[i*ldc+j], reducing WAW
    }
}
}
