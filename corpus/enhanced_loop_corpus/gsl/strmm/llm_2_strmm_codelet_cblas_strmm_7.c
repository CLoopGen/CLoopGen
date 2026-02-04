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
        float temp = 0.;
        float *a_row_start = &A[lda * j];
        float *b_row_start = &B[i * ldb];
        for (k = 0; k < j; k++) {
            temp += a_row_start[k] * b_row_start[k];
        }
        if (nonunit) {
            temp += a_row_start[j] * b_row_start[j];
        } else {
            temp += b_row_start[j];
        }
        b_row_start[j] = alpha * temp;
    }
}
}
