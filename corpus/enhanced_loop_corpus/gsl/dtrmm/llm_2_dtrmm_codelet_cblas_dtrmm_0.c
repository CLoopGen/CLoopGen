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
        int idx_i = i * lda;
        int idx_j = j;
        if (nonunit) {
            temp = A[idx_i + i] * B[i * ldb + idx_j];
        } else {
            temp = B[i * ldb + idx_j];
        }
        for (k = i + 1; k < n1; k++) {
            int a_offset = idx_i + k;
            int b_offset = k * ldb + idx_j;
            temp += A[a_offset] * B[b_offset];
        }
        B[i * ldb + idx_j] = alpha * temp;
    }
}
}
