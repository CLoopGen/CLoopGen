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
        if (nonunit) {
            float Ajj = A[j * lda + j];  // Strided access: using row-major interpretation with lda stride
            B[i * ldb + j] /= Ajj;
        }
        float Bij = B[i * ldb + j];
        for (k = j + 1; k < n2; k++) {
            B[i * ldb + k] -= A[j * lda + k] * Bij;  // Consecutive in k, strided in j and A's rows
        }
    }
}
}
