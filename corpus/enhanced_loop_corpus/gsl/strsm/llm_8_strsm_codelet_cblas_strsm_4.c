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
for (i = 0; i < n1; i += 2) {
    if (nonunit) {
        float Aii0 = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii0;
        }
        if (i + 1 < n1) {
            float Aii1 = A[lda * (i+1) + (i+1)];
            for (j = 0; j < n2; j++) {
                B[ldb * (i+1) + j] /= Aii1;
            }
        }
    }
    for (k = i + 1; k < n1; k++) {
        const float Aki = A[k * lda + i];
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= Aki * B[ldb * i + j];
        }
    }
    if (i + 1 < n1) {
        for (k = i + 2; k < n1; k++) {
            const float Akii = A[k * lda + (i+1)];
            for (j = 0; j < n2; j++) {
                B[ldb * k + j] -= Akii * B[ldb * (i+1) + j];
            }
        }
    }
}
}
