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
    float temp_real_inner;
    float temp_imag_inner;
    for (j = 0; j <= i; j++) {
        temp_real_inner = 0.;
        temp_imag_inner = 0.;
        k = 0;
        for (; k < K; k++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real_inner += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag_inner += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real_inner - alpha_imag * temp_imag_inner;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag_inner + alpha_imag * temp_real_inner;
    }
}
}
