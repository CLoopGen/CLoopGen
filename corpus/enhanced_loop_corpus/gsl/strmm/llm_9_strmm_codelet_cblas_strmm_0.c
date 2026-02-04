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
    for (j = 0; j < n2; j += 2) {
        float temp1 = 0., temp2 = 0.;
        int j1 = j, j2 = j + 1;
        if (nonunit) {
            temp1 = A[i * lda + i] * B[i * ldb + j1];
            if (j2 < n2) {
                temp2 = A[i * lda + i] * B[i * ldb + j2];
            }
        } else {
            temp1 = B[i * ldb + j1];
            if (j2 < n2) {
                temp2 = B[i * ldb + j2];
            }
        }
        for (k = i + 1; k < n1; k++) {
            temp1 += A[lda * i + k] * B[k * ldb + j1];
            if (j2 < n2) {
                temp2 += A[lda * i + k] * B[k * ldb + j2];
            }
        }
        B[ldb * i + j1] = alpha * temp1;
        if (j2 < n2) {
            B[ldb * i + j2] = alpha * temp2;
        }
    }
}
}
