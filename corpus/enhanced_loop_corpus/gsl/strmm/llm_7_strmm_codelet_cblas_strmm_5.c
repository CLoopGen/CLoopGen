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
        float sum = 0.0;
        int diag_A = j * lda + j;
        int base_B = i * ldb;
        // Introduce loop-carried dependency via pipelined accumulation in k-loop
        for (k = j; k < n2; k++) {
            if (k == j) {
                if (nonunit) {
                    temp = A[diag_A] * B[base_B + j];
                } else {
                    temp = B[base_B + j];
                }
            } else {
                temp += A[j * lda + k] * B[base_B + k];
            }
        }
        B[base_B + j] = alpha * temp;
    }
}
}
