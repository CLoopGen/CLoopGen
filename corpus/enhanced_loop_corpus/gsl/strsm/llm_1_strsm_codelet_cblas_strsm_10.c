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
            float Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        float Bij = B[ldb * i + j];
        k = 0;
        if (j > 0) {
            for (int kk = 0; kk < j; kk += 4) {
                if (kk + 0 < j) B[ldb * i + kk + 0] -= A[(kk + 0) * lda + j] * Bij;
                if (kk + 1 < j) B[ldb * i + kk + 1] -= A[(kk + 1) * lda + j] * Bij;
                if (kk + 2 < j) B[ldb * i + kk + 2] -= A[(kk + 2) * lda + j] * Bij;
                if (kk + 3 < j) B[ldb * i + kk + 3] -= A[(kk + 3) * lda + j] * Bij;
            }
        }
    }
}
}
