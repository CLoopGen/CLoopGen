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
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        real = 0;
        imag = 0;
        float temp_real = 0;
        float temp_imag = 0;
        for (l = 0; l < K; l++) {
            temp_real += alpha0 * C[l * 2];
            temp_imag -= alpha1 * C[l * 2 + 1];
        }
        real = temp_real;
        imag = temp_imag;
        tmp0 = beta0 * C[j * 2 * ldc + 2 * i] - beta1 * C[j * 2 * ldc + 2 * i + 1];
        tmp1 = beta0 * C[j * 2 * ldc + 2 * i + 1] + beta1 * C[j * 2 * ldc + 2 * i];
        C[j * 2 * ldc + 2 * i] = tmp0 + real;
        C[j * 2 * ldc + 2 * i + 1] = tmp1 + imag;
    }
}
}
