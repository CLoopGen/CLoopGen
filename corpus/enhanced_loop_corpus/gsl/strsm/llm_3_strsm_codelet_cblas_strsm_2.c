#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
float *base_B, *col_B_i, *col_B_k;
for (i = 0; i < n1; i++) {
    base_B = &B[ldb * i];
    if (nonunit) {
        float Aii = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            base_B[j] /= Aii;
        }
    }
    for (k = i + 1; k < n1; k++) {
        const float Aik = A[i * lda + k];
        col_B_i = &B[ldb * i];
        col_B_k = &B[ldb * k];
        for (j = 0; j < n2; j++) {
            col_B_k[j] -= Aik * col_B_i[j];
        }
    }
}
}
