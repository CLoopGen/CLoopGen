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
    for (j = n2 - 1; j >= 0; j--) {
        float temp = 0.0f;
        float *A_col_base = &A[j];
        float *B_row_base = &B[i * ldb];
        for (k = 0; k < j; k++) {
            temp += A_col_base[lda * k] * B_row_base[k];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B_row_base[j];
        } else {
            temp += B_row_base[j];
        }
        B_row_base[j] = alpha * temp;
    }
}
}
