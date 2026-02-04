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
    if (nonunit) {
        float Aii = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] *= (1.0f / Aii);
        }
    }
    for (k = i + 1; k < n1; k++) {
        const float Aki = A[k * lda + i];
        for (j = n2 - 1; j >= 0; j--) {
            B[ldb * k + j] -= Aki * B[ldb * i + j];
        }
    }
}
}
