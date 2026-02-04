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
    for (j = n2 - 1; j >= 0; j--) {
        if (nonunit && A[lda * j + j] != 0.0f) {
            float inv_Ajj = 1.0f / A[lda * j + j];
            B[ldb * i + j] *= inv_Ajj;
        }
        float Bij = B[ldb * i + j];
        for (k = j - 1; k >= 0; k--) {
            B[ldb * i + k] -= A[j * lda + k] * Bij;
        }
    }
}
}
