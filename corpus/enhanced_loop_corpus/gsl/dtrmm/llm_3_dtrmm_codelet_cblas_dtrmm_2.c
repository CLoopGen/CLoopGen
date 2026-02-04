#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
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
// Transpose the loop order to improve spatial locality in B by iterating over j first at the outer level
for (j = 0; j < n2; j++) {
    for (i = n1; i > 0 && i--;) {
        double temp = 0.;
        // Use strided access with precomputed base indices for better predictability
        int base_A = lda * i;
        int base_B_col = j;
        for (k = 0; k < i; k++) {
            temp += A[base_A + k] * B[k * ldb + base_B_col];
        }
        if (nonunit) {
            temp += A[base_A + i] * B[i * ldb + base_B_col];
        } else {
            temp += B[i * ldb + base_B_col];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
