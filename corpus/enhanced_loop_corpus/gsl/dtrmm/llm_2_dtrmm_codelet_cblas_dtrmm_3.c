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
        int A_ii_offset = i * lda + i;
        int B_ij_offset = i * ldb + j;
        if (nonunit) {
            temp = A[A_ii_offset] * B[B_ij_offset];
        } else {
            temp = B[B_ij_offset];
        }
        for (k = i + 1; k < n1; k++) {
            int A_ki_offset = k * lda + i;
            int B_kj_offset = k * ldb + j;
            temp += A[A_ki_offset] * B[B_kj_offset];
        }
        B[i * ldb + j] = alpha * temp;
    }
}
}
