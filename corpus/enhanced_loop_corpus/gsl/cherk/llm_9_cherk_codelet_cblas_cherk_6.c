#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        float temp_real0 = 0., temp_real1 = 0.;
        float temp_imag0 = 0., temp_imag1 = 0.;
        int bound = (i + 1 < N) ? K : 0;
        for (k = 0; k < K; k++) {
            const float Aki_real0 = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag0 = -(((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real0 += Aki_real0 * Akj_real - Aki_imag0 * Akj_imag;
            temp_imag0 += Aki_real0 * Akj_imag + Aki_imag0 * Akj_real;

            if (bound) {
                const float Aki_real1 = (((const float *)A)[2 * (k * lda + i + 1)]);
                const float Aki_imag1 = -(((const float *)A)[2 * (k * lda + i + 1) + 1]);
                temp_real1 += Aki_real1 * Akj_real - Aki_imag1 * Akj_imag;
                temp_imag1 += Aki_real1 * Akj_imag + Aki_imag1 * Akj_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag0;
        if (bound) {
            (((float *)C)[2 * ((i + 1) * ldc + j)]) += alpha * temp_real1;
            (((float *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha * temp_imag1;
        }
    }
    if (i + 1 < N) {
        for (j = i + 1; j < N; j++) {
            float temp_real = 0., temp_imag = 0.;
            for (k = 0; k < K; k++) {
                const float Aki_real = (((const float *)A)[2 * (k * lda + i + 1)]);
                const float Aki_imag = -(((const float *)A)[2 * (k * lda + i + 1) + 1]);
                const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
                const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
                temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
                temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
            }
            (((float *)C)[2 * ((i + 1) * ldc + j)]) += alpha * temp_real;
            (((float *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha * temp_imag;
        }
    }
}
}
