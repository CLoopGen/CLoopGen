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
        int offset_B = i * ldb + j;
        if (nonunit) {
            temp = A[j * lda + j] * B[offset_B];
        } else {
            temp = B[offset_B];
        }
        for (k = j + 1; k < n2; k++) {
            int offset_A = j * lda + k;
            int offset_B_k = i * ldb + k;
            temp += A[offset_A] * B[offset_B_k];
        }
        B[offset_B] = alpha * temp;
    }
}
}
