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
        float Bij = B[ldb * i + j];
        if (nonunit && j < n2) {
            float Ajj = A[lda * j + j];
            B[ldb * i + j] = Bij / Ajj;
        }
        for (k = 0; k < j; k++) {
            B[ldb * i + k] -= A[k * lda + j] * Bij;
        }
    }
}
}
