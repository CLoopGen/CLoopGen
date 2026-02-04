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
            float Ajj = A[j * lda + j];
            B[i * ldb + j] /= Ajj;
        }
        {
            float Bij = B[i * ldb + j];
            for (k = j + 1; k < n2; k += 2) {
                if (k + 1 < n2) {
                    B[i * ldb + k] -= A[k * lda + j] * Bij;
                    B[i * ldb + k + 1] -= A[(k + 1) * lda + j] * Bij;
                } else {
                    B[i * ldb + k] -= A[k * lda + j] * Bij;
                }
            }
            if (n2 % 2 == 0 && j + 1 < n2) {
                k = n2 - 1;
                B[i * ldb + k] -= A[k * lda + j] * Bij;
            }
        }
    }
}
}
