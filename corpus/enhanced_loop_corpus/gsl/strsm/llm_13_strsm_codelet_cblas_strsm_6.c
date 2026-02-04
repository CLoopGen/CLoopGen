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
float *b_row_ptr, *b_k_ptr, *b_i_ptr;
for (i = n1; i > 0 && i--;) {
    if (nonunit) {
        float Aii = A[lda * i + i];
        b_i_ptr = &B[ldb * i];
        for (j = 0; j < n2; j++) {
            b_i_ptr[j] /= Aii;
        }
    }
    b_i_ptr = &B[ldb * i];
    for (k = 0; k < i; k++) {
        const float Aik = A[i * lda + k];
        b_k_ptr = &B[ldb * k];
        for (j = 0; j < n2; j++) {
            b_k_ptr[j] -= Aik * b_i_ptr[j];
        }
    }
}
}
