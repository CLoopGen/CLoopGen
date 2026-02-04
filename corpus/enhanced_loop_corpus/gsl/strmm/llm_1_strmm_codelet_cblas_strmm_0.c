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
for (i = 0; i < n1; i++) {
    for (k = i + 1; k < n1; k++) {
        float a_ik = A[lda * i + k];
        for (j = 0; j < n2; j++) {
            B[i * ldb + j] += a_ik * B[k * ldb + j];
        }
    }
    for (j = 0; j < n2; j++) {
        float temp = nonunit ? A[i * lda + i] * B[i * ldb + j] : B[i * ldb + j];
        B[i * ldb + j] = alpha * temp;
    }
}
}
