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
for (i = n1; i > 0 && i--;) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        int idx_i = i * ldb + j;
        int a_offset = lda * i + i;
        for (k = 0; k < i; k++) {
            int a_index = lda * k + i;
            int b_index = k * ldb + j;
            temp += A[a_index] * B[b_index];
        }
        if (nonunit) {
            temp += A[a_offset] * B[idx_i];
        } else {
            temp += B[idx_i];
        }
        B[idx_i] = alpha * temp;
    }
}
}
