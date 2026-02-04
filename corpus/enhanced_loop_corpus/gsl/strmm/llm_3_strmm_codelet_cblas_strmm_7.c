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
    float *b_row = &B[i * ldb];
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        float *a_col = &A[j];
        for (k = 0; k < j; k++) {
            temp += A[lda * j + k] * b_row[k];
        }
        if (nonunit) {
            temp += A[lda * j + j] * b_row[j];
        } else {
            temp += b_row[j];
        }
        b_row[j] = alpha * temp;
    }
}
}
