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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        double temp = 0.;
        int b_row_offset = i * ldb;
        int b_col_base = j;
        int b_index = b_row_offset + b_col_base;
        if (nonunit) {
            temp = A[i * lda + i] * B[b_index];
        } else {
            temp = B[b_index];
        }
        for (k = i + 1; k < n1; k++) {
            int a_index = i * lda + k;
            int b_k_index = k * ldb + b_col_base;
            temp += A[a_index] * B[b_k_index];
        }
        B[b_index] = alpha * temp;
    }
}
}
