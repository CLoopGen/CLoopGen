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
    float temp_store;
    for (j = 0; j < n2; j++) {
        temp_store = 0.;
        if (nonunit) {
            temp_store = A[i * lda + i] * B[i * ldb + j];
        } else {
            temp_store = B[i * ldb + j];
        }
        for (k = i + 1; k < n1; k++) {
            temp_store += A[lda * i + k] * B[k * ldb + j];
        }
        B[ldb * i + j] = alpha * temp_store;
    }
}
}
