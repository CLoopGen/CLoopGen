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
for (i = 0; i < N; i++) {
    float temp_buffer[N];
    for (j = i; j < N; j++) {
        temp_buffer[j] = 0.0f;
    }
    for (k = 0; k < K; k++) {
        float a_ki = A[k * lda + i];
        for (j = i; j < N; j++) {
            temp_buffer[j] += a_ki * A[k * lda + j];
        }
    }
    for (j = i; j < N; j++) {
        C[i * ldc + j] += alpha * temp_buffer[j];
    }
}
}
