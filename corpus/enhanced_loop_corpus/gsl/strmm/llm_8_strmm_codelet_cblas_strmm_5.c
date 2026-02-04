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
        float temp = 0.0f;
        int base_idx_A = j * lda;
        int base_idx_B = i * ldb;
        if (nonunit) {
            temp = A[base_idx_A + j] * B[base_idx_B + j];
        } else {
            temp = B[base_idx_B + j];
        }
        for (k = j + 1; k < n2; k += 2) {
            if (k + 1 < n2) {
                temp += A[base_idx_A + k] * B[base_idx_B + k] +
                        A[base_idx_A + k + 1] * B[base_idx_B + k + 1];
            } else {
                temp += A[base_idx_A + k] * B[base_idx_B + k];
            }
        }
        B[base_idx_B + j] = alpha * temp;
    }
}
}
