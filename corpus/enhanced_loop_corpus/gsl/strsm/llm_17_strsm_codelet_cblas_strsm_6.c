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
    float Aii_local = nonunit ? A[lda * i + i] : 1.0f;
    if (nonunit) {
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii_local;
        }
    }
    float B_cache[n2];
    for (j = 0; j < n2; j++) {
        B_cache[j] = B[ldb * i + j];
    }
    for (k = 0; k < i; k++) {
        const float Aik = A[i * lda + k];
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aik * B_cache[j];
        }
    }
}
}
