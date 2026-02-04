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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        float temp = 0.;
        int B_idx = i * ldb + j;
        if (nonunit) {
            temp = A[i * lda + i] * B[B_idx];
        } else {
            temp = B[B_idx];
        }
        for (k = i + 1; k < n1; k++) {
            temp += A[k * lda + i] * B[k * ldb + j];
        }
        B[B_idx] = alpha * temp;
    }
}
}
