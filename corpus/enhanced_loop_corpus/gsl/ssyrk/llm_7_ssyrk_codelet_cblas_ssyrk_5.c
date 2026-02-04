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
        for (k = 0; k < K; k++) {
            float a_ik = A[k * lda + i];
            for (j = i; j < N; j++) {
                float a_kj = A[k * lda + j];
                temp_arr[j] = (k == 0) ? 0.0f : temp_arr[j];
                temp_arr[j] += a_ik * a_kj;
            }
        }
        for (j = i; j < N; j++) {
            C[i * ldc + j] += alpha * temp_arr[j];
        }
    }
}
