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
        // Introduce a read-after-write dependency by reordering access and using a local accumulator
        // Also remove loop-carried dependency on B by deferring write until after inner computation
        for (k = j; k < n2; k++) {
            if (k == j) {
                if (nonunit) {
                    temp = A[j * lda + j] * B[i * ldb + j];
                } else {
                    temp = B[i * ldb + j];
                }
            } else {
                temp += A[lda * k + j] * B[i * ldb + k];
            }
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
