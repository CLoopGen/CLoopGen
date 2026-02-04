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
    for (j = n2; j > 0 && j--;) {
        float Ajj = A[lda * j + j];
        float Bij = B[ldb * i + j];
        if (nonunit) {
            Bij /= Ajj;
            B[ldb * i + j] = Bij;
        }
        for (k = 0; k < j; k++) {
            B[ldb * i + k] -= A[j * lda + k] * Bij;
        }
    }
}
}
