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
for (i = n1; i > 0 && i--;) {
    if (nonunit) {
        float Aii = A[lda * i + i];
        int idx_i = ldb * i;
        for (j = 0; j < n2; j++) {
            B[idx_i + j] /= Aii;
        }
    }
    int ik = 0;
    for (k = 0; k < i; k++) {
        const float Aik = A[i * lda + k];
        int idx_k = ldb * k;
        int idx_i = ldb * i;
        for (j = 0; j < n2; j++) {
            B[idx_k + j] -= Aik * B[idx_i + j];
        }
        ik++;
    }
}
}
