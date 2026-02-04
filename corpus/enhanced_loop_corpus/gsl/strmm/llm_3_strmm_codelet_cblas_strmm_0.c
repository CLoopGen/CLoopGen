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
        int B_index = i * ldb + j;
        if (nonunit) {
            temp = A[i * lda + i] * B[B_index];
        } else {
            temp = B[B_index];
        }
        for (k = i + 1; k < n1; k++) {
            temp += A[i * lda + k] * B[k * ldb + j];
        }
        B[B_index] = alpha * temp;
    }
}
}
