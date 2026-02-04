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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        int idx_i_j_B = i * ldb + j;
        int idx_diag_A = i * lda + i;
        int idx_col_A_base = i;
        int idx_B_base = i * ldb;

        if (nonunit) {
            temp = A[idx_diag_A] * B[idx_i_j_B];
        } else {
            temp = B[idx_i_j_B];
        }

        for (k = i + 1; k < n1; k++) {
            int access_A = lda * k + idx_col_A_base;
            int access_B = k * ldb + j;
            temp += A[access_A] * B[access_B];
        }

        B[idx_i_j_B] = alpha * temp;
    }
}
}
