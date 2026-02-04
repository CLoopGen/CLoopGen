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
        // Introduce loop-carried dependence by accumulating temp2 across k with delayed write to C
        for (k = 0; k < i; k++) {
            const double Aik = A[i * lda + k];
            temp2 += Aik * B[ldb * k + j];  // temp2 now accumulates before any update to C
            C[k * ldc + j] += Aik * temp1; // This remains a WAR-safe access (no loop-carried dep here)
        }
        // Now apply the accumulated temp2 in a single update
        C[i * ldc + j] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
