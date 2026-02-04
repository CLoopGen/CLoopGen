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
        j = 0;
        do {
            B[ldb * i + j] /= Aii;
            j++;
        } while (j < n2);
    }
    k = 0;
    while (k < i) {
        const float Aki = A[k * lda + i];
        j = 0;
        while (j < n2) {
            B[ldb * k + j] -= Aki * B[ldb * i + j];
            j++;
        }
        k++;
    }
}
}
