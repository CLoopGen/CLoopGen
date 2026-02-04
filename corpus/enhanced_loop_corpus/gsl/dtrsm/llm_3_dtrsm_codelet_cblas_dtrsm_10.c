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
double *base_B, *addr_A;
for (i = 0; i < n1; i++) {
    base_B = &B[i * ldb]; // Base pointer for row i of B to enable consecutive-like indexing
    for (j = n2; j > 0; --j) {
        int j_idx = j - 1; // Adjust index to avoid post-decrement in condition
        if (nonunit) {
            double Ajj = A[j_idx * lda + j_idx]; // Direct diagonal element access
            base_B[j_idx] /= Ajj;
        }
        double Bij = base_B[j_idx];
        addr_A = &A[j_idx]; // Point to column j of A (strided access base)
        for (k = 0; k < j_idx; k++) {
            base_B[k] -= addr_A[k * lda] * Bij; // Strided access through offset base pointer
        }
    }
}
}
