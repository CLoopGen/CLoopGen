#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *A;
extern  int lda;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse loop iteration order to alter loop-carried dependencies
// Now processing from i = 0 to i < n1, changing direction of dependence
for (i = 0; i < n1; i++) {
    if (nonunit) {
        double Aii = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii;
        }
    }
    // Modify loop bounds and access pattern to change dependency flow
    // Instead of k < i, we now process k from i+1 to n1 (forward elimination style)
    for (k = i + 1; k < n1; k++) {
        const double Aik = A[k * lda + i]; // Transposed access pattern
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aik * B[ldb * i + j];
        }
    }
}
}
