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
        for (j = 0; j < n2; j += 4) {
            if (j < n2)       B[ldb * i + j] /= Aii;
            if (j + 1 < n2)   B[ldb * i + j + 1] /= Aii;
            if (j + 2 < n2)   B[ldb * i + j + 2] /= Aii;
            if (j + 3 < n2)   B[ldb * i + j + 3] /= Aii;
        }
    }
    for (k = i + 1; k < n1; k++) {
        const float Aki = A[k * lda + i];
        for (j = 0; j < n2; j += 4) {
            if (j < n2)         B[ldb * k + j] -= Aki * B[ldb * i + j];
            if (j + 1 < n2)     B[ldb * k + j + 1] -= Aki * B[ldb * i + j + 1];
            if (j + 2 < n2)     B[ldb * k + j + 2] -= Aki * B[ldb * i + j + 2];
            if (j + 3 < n2)     B[ldb * k + j + 3] -= Aki * B[ldb * i + j + 3];
        }
    }
}
}
