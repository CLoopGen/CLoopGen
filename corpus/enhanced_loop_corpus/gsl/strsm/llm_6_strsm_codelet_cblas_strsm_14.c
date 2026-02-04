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
    for (j = 0; j < n2; j++) {
        float temp = 0.0f;
        if (nonunit) {
            float Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        for (k = j + 1; k < n2; k++) {
            temp = A[k * lda + j] * B[ldb * i + j];
            B[ldb * i + k] -= temp;
        }
    }
}
}
