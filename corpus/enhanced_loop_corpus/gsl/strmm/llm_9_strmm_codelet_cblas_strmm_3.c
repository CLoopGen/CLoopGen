#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
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
for (i = 1; i < n1; i *= 2) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        if (nonunit && i < n1) {
            temp = A[i * lda + i] * B[i * ldb + j];
        } else if (i < n1) {
            temp = B[i * ldb + j];
        }
        for (k = i + 1; k < n1 && k <= i * 2; k++) {
            temp += A[lda * k + i] * B[k * ldb + j];
        }
        if (i < n1) {
            B[ldb * i + j] = alpha * temp;
        }
    }
}
}
