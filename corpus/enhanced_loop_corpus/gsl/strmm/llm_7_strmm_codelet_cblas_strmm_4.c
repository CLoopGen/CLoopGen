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
    float temp_storage[64];
    int limit = n2 < 64 ? n2 : 64;
    for (j = 0; j < limit; j++) {
        temp_storage[j] = 0.0f;
        for (k = 0; k < j; k++) {
            temp_storage[j] += A[lda * k + j] * B[i * ldb + k];
        }
        if (nonunit) {
            temp_storage[j] += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp_storage[j] += B[i * ldb + j];
        }
    }
    for (j = 0; j < limit; j++) {
        B[ldb * i + j] = alpha * temp_storage[j];
    }
}
}
