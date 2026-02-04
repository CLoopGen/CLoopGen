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
    float *Bi = &B[i * ldb];
    for (j = n2; j > 0; --j) {
        int idx_j = j - 1;
        if (nonunit) {
            float Ajj = A[(lda + 1) * idx_j];
            Bi[idx_j] /= Ajj;
        }
        float Bij = Bi[idx_j];
        float *A_row_j = &A[idx_j * lda];
        for (k = 0; k < idx_j; k++) {
            Bi[k] -= A_row_j[k] * Bij;
        }
    }
}
}
