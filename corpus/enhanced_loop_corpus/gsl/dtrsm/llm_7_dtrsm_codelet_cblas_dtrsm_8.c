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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double Bij;
        if (nonunit) {
            double Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        Bij = B[ldb * i + j];
        // Reverse the order of memory updates to introduce different dependency chain
        // Now all uses of Bij are based on loaded value before any write to B[i][j]
        for (k = n2 - 1; k > j; k--) {
            B[ldb * i + k] -= A[j * lda + k] * Bij;
        }
    }
}
}
