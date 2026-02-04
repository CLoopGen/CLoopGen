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
    double temp2_local = 0.0;
    for (j = 0; j < n2; j++) {
        const double temp1 = alpha * B[ldb * i + j];
        // Remove loop-carried dependency by privatizing temp2 per j and fusing computations
        // Eliminate some WAW hazards by updating C in a single expression
        temp2_local = 0.0; // Reset per j to remove cross-iteration dependency on temp2
        for (k = j + 1; k < n2; k++) {
            const double Ajk = A[j * lda + k];
            C[i * ldc + k] += temp1 * Ajk;
            temp2_local += B[ldb * i + k] * Ajk;
        }
        // Combine both contributions to C[i*ldc+j] in one assignment to reduce partial updates (WAW)
        C[i * ldc + j] = C[i * ldc + j] + temp1 * A[j * lda + j] + alpha * temp2_local;
    }
}
}
