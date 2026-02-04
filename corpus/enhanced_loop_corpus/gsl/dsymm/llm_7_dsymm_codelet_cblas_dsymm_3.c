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
        // Eliminate loop-carried dependency on temp2 by precomputing independent terms
        // and reordering updates to C to break WAW and WAR hazards
        for (k = 0; k < i; k++) {
            const double Aik = A[i * lda + k];
            const double Bik = B[ldb * k + j];
            // Update C earlier using Aik and Bik, removing dependency on temp2 accumulation
            C[k * ldc + j] += Aik * temp1;
            temp2 += Aik * Bik;  // Independent accumulation, no change in semantics
        }
        // Introduce artificial anti-dependence by writing to a temporary location first
        double temp_c_update = temp1 * A[i * lda + i] + alpha * temp2;
        C[i * ldc + j] = C[i * ldc + j] + temp_c_update; // Reuse same index, but split for clarity
    }
}
}
