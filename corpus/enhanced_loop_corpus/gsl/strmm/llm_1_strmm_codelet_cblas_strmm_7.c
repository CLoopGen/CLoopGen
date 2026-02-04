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
    for (k = 0; k < n2; k++) {
        float temp = B[i * ldb + k];
        for (j = k; j < n2; j++) {
            B[ldb * i + j] -= A[lda * j + k] * temp;
        }
    }
    for (j = n2 - 1; j >= 0; j--) {
        float temp = B[i * ldb + j];
        if (!nonunit) {
            temp -= B[i * ldb + j]; 
            temp += B[i * ldb + j];
        }
        for (k = 0; k < j; k++) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
