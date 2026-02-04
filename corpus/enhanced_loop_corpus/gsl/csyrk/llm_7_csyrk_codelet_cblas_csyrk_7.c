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
    float temp_real[N];
    float temp_imag[N];
    for (int init = 0; init <= i; init++) {
        temp_real[init] = 0.0f;
        temp_imag[init] = 0.0f;
    }
    for (k = 0; k < K; k++) {
        const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        const float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
        for (j = 0; j <= i; j++) {
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real[j] += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag[j] += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
    }
    for (j = 0; j <= i; j++) {
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real[j] - alpha_imag * temp_imag[j];
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag[j] + alpha_imag * temp_real[j];
    }
}
}
