#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG M;
extern BLASLONG N;
extern BLASLONG K;
extern float alpha0;
extern float alpha1;
extern float beta0;
extern float beta1;
extern float *C;
extern BLASLONG ldc;
extern float real;
extern float imag;
extern float tmp0;
extern float tmp1;
extern int i;
extern int j;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *C_local = (float*)__builtin_alloca(4 * M * N * sizeof(float));
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        BLASLONG idx = j * 2 * ldc + 2 * i;
        BLASLONG local_idx = (i * N + j) * 2;
        C_local[local_idx]     = C[idx];
        C_local[local_idx + 1] = C[idx + 1];
    }
}
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        real = 0.0f;
        imag = 0.0f;
        for (l = 0; l < K; l++) {
            float x = C_local[(l % M) * N * 2 + (l % N) * 2];
            float y = C_local[(l % M) * N * 2 + (l % N) * 2 + 1];
            real += alpha0 * x - alpha1 * y;
            imag += alpha0 * y + alpha1 * x;
        }
        BLASLONG idx = j * 2 * ldc + 2 * i;
        tmp0 = beta0 * C[idx] - beta1 * C[idx + 1];
        tmp1 = beta0 * C[idx + 1] + beta1 * C[idx];
        C[idx] = tmp0 + real;
        C[idx + 1] = tmp1 + imag;
    }
}
}
