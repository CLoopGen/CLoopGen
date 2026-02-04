#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        k = 0;
        #pragma unroll(4)
        for (; k + 3 < K; k += 4) {
            const float Aik_real0 = (((const float *)A)[2 * (i * lda + k + 0)]);
            const float Aik_imag0 = (((const float *)A)[2 * (i * lda + k + 0) + 1]);
            const float Ajk_real0 = (((const float *)A)[2 * (j * lda + k + 0)]);
            const float Ajk_imag0 = (((const float *)A)[2 * (j * lda + k + 0) + 1]);

            const float Aik_real1 = (((const float *)A)[2 * (i * lda + k + 1)]);
            const float Aik_imag1 = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
            const float Ajk_real1 = (((const float *)A)[2 * (j * lda + k + 1)]);
            const float Ajk_imag1 = (((const float *)A)[2 * (j * lda + k + 1) + 1]);

            const float Aik_real2 = (((const float *)A)[2 * (i * lda + k + 2)]);
            const float Aik_imag2 = (((const float *)A)[2 * (i * lda + k + 2) + 1]);
            const float Ajk_real2 = (((const float *)A)[2 * (j * lda + k + 2)]);
            const float Ajk_imag2 = (((const float *)A)[2 * (j * lda + k + 2) + 1]);

            const float Aik_real3 = (((const float *)A)[2 * (i * lda + k + 3)]);
            const float Aik_imag3 = (((const float *)A)[2 * (i * lda + k + 3) + 1]);
            const float Ajk_real3 = (((const float *)A)[2 * (j * lda + k + 3)]);
            const float Ajk_imag3 = (((const float *)A)[2 * (j * lda + k + 3) + 1]);

            temp_real += Aik_real0 * Ajk_real0 - Aik_imag0 * Ajk_imag0;
            temp_imag += Aik_real0 * Ajk_imag0 + Aik_imag0 * Ajk_real0;

            temp_real += Aik_real1 * Ajk_real1 - Aik_imag1 * Ajk_imag1;
            temp_imag += Aik_real1 * Ajk_imag1 + Aik_imag1 * Ajk_real1;

            temp_real += Aik_real2 * Ajk_real2 - Aik_imag2 * Ajk_imag2;
            temp_imag += Aik_real2 * Ajk_imag2 + Aik_imag2 * Ajk_real2;

            temp_real += Aik_real3 * Ajk_real3 - Aik_imag3 * Ajk_imag3;
            temp_imag += Aik_real3 * Ajk_imag3 + Aik_imag3 * Ajk_real3;
        }
        for (; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
