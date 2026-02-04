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
        // Also introduce a local RAW dependency via reordered operations
        for (k = j + 1; k < n2; k++) {
            const double Ajk = A[j * lda + k];
            temp2 += B[ldb * i + k] * Ajk;
            C[i * ldc + k] += temp1 * Ajk; // Move this after temp2 accumulation to change RAW order
        }
        C[i * ldc + j] += temp1 * A[j * lda + j]; // Update after inner loop to create loop-carried WAW
        C[i * ldc + j] += alpha * temp2;
    }
}
}
