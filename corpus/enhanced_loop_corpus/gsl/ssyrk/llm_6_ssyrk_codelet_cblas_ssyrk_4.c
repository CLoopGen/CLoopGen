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
        float temp_local[N];
        for (j = 0; j < N; j++) {
            temp_local[j] = 0.0f;
        }
        for (k = 0; k < K; k++) {
            float a_ik = A[i * lda + k];
            for (j = i; j < N; j++) {
                temp_local[j] += a_ik * A[j * lda + k];
            }
        }
        for (j = i; j < N; j++) {
            C[i * ldc + j] += alpha * temp_local[j];
        }
    }
}
