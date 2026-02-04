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
for (i = n1; i > 0 && i--;) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        int a_index_base = i;
        int b_index_diag = i * ldb + j;
        for (k = 0; k < i; k++) {
            int a_index = a_index_base + lda * k;
            int b_index = k * ldb + j;
            temp += A[a_index] * B[b_index];
        }
        if (nonunit) {
            temp += A[i * lda + i] * B[b_index_diag];
        } else {
            temp += B[b_index_diag];
        }
        B[i * ldb + j] = alpha * temp;
    }
}
}
