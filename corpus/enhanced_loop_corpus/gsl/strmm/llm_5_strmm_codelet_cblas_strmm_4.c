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
    for (j = n2; --j >= 0;) {
        float temp = 0.0f;
        int diag_index = j * lda + j;
        int b_index_j = i * ldb + j;
        for (k = 0; k < j; k++) {
            temp += A[lda * k + j] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[diag_index] * B[b_index_j];
        } else {
            temp += B[b_index_j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
