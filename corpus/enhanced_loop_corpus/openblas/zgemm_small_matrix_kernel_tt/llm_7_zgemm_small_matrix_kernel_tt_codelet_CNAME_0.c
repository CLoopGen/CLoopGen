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
    float local_beta0 = beta0 + i * 0.001f;
    float local_beta1 = beta1 - i * 0.001f;
    for (j = 0; j < N; j++) {
        float prev_real = real;
        real = 0;
        imag = 0;
        for (l = 0; l < K; l++) {
            float coeff = (l % 2 == 0) ? 1.0f : -1.0f;
            real += coeff * (alpha0 + l);
            imag += coeff * (alpha1 - l);
        }
        tmp0 = local_beta0 * C[j * 2 * ldc + 2 * i] - local_beta1 * C[j * 2 * ldc + 2 * i + 1];
        tmp1 = local_beta0 * C[j * 2 * ldc + 2 * i + 1] + local_beta1 * C[j * 2 * ldc + 2 * i];
        C[j * 2 * ldc + 2 * i] = tmp0 + alpha0 * real - alpha1 * imag + (i > 0 ? prev_real * 0.01f : 0);
        C[j * 2 * ldc + 2 * i + 1] = tmp1 + alpha0 * imag + real * alpha1;
    }
}
}
