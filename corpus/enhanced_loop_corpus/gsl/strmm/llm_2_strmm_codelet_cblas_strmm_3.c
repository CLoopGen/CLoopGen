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
        int A_offset_ii = i * lda + i;
        int B_offset_ij = i * ldb + j;
        if (nonunit) {
            temp = A[A_offset_ii] * B[B_offset_ij];
        } else {
            temp = B[B_offset_ij];
        }
        for (k = i + 1; k < n1; k++) {
            int A_offset_ki = lda * k + i;
            int B_offset_kj = k * ldb + j;
            temp += A[A_offset_ki] * B[B_offset_kj];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
