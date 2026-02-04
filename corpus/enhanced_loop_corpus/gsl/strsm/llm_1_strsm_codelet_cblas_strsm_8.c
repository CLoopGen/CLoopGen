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
            float Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        float Bij = B[ldb * i + j];
        k = j + 1;
        if (k < n2) {
            do {
                B[ldb * i + k] -= A[j * lda + k] * Bij;
                k++;
            } while (k < n2);
        }
    }
}
}
