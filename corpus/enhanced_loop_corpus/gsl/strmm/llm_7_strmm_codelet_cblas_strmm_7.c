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
float *temp_arr = (float*)alloca(n2 * sizeof(float));
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        for (k = 0; k < j; k++) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        temp_arr[j] = alpha * temp;
    }
    for (j = 0; j < n2; j++) {
        B[ldb * i + j] = temp_arr[j];
    }
}
}
