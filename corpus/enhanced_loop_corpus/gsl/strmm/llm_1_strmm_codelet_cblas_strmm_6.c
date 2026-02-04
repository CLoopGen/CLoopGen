#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *B;
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
        float temp = 0.;
        int idx_jj = j * lda + j;
        int idx_bi_j = i * ldb + j;
        if (nonunit) {
            temp = A[idx_jj] * B[idx_bi_j];
        } else {
            temp = B[idx_bi_j];
        }
        for (int m = j + 1; m < n2; m++) {
            int idx_akj = lda * m + j;
            int idx_bim = i * ldb + m;
            temp += A[idx_akj] * B[idx_bim];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
