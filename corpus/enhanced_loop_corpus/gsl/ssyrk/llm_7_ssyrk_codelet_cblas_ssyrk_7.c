#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *temp_arr = (float*)alloca(N * sizeof(float));
for (i = 0; i < N; i++) {
    temp_arr[i] = 0.0;
    for (k = 0; k < K; k++) {
        temp_arr[i] += A[k * lda + i] * A[k * lda + i];
    }
    for (j = 0; j <= i; j++) {
        float temp = 0.0;
        for (k = 0; k < K; k++) {
            temp += A[k * lda + i] * A[k * lda + j];
        }
        if (i == j) {
            C[i * ldc + j] += alpha * temp_arr[i];
        } else {
            C[i * ldc + j] += alpha * temp;
        }
    }
}
}
