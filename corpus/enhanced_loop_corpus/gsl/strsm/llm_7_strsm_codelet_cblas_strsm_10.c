#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
    float temp[n2];
    for (j = 0; j < n2; j++) {
        temp[j] = nonunit ? A[lda * j + j] : 1.0f;
    }
    for (j = n2 - 1; j >= 0; j--) {
        if (nonunit) {
            B[ldb * i + j] /= temp[j];
        }
        float Bij = B[ldb * i + j];
        for (k = 0; k < j; k++) {
            B[ldb * i + k] -= A[k * lda + j] * Bij;
        }
    }
}
}
