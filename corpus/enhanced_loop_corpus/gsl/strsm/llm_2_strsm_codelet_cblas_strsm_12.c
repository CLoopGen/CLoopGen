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
        if (nonunit) {
            float Ajj = A[j * (lda + 1)];
            B[i * ldb + j] *= (1.0f / Ajj);
        }
        float Bij = B[i * ldb + j];
        for (k = j - 1; k >= 0; k--) {
            B[i * ldb + k] -= A[j * lda + k] * Bij;
        }
    }
}
}
