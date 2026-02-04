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
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        k = 0;
        while (k < K - 3) {
            const float Aki_real0 = (((const float *)A)[2 * ((k+0) * lda + i)]);
            const float Aki_imag0 = -(((const float *)A)[2 * ((k+0) * lda + i) + 1]);
            const float Akj_real0 = (((const float *)A)[2 * ((k+0) * lda + j)]);
            const float Akj_imag0 = (((const float *)A)[2 * ((k+0) * lda + j) + 1]);

            const float Aki_real1 = (((const float *)A)[2 * ((k+1) * lda + i)]);
            const float Aki_imag1 = -(((const float *)A)[2 * ((k+1) * lda + i) + 1]);
            const float Akj_real1 = (((const float *)A)[2 * ((k+1) * lda + j)]);
            const float Akj_imag1 = (((const float *)A)[2 * ((k+1) * lda + j) + 1]);

            const float Aki_real2 = (((const float *)A)[2 * ((k+2) * lda + i)]);
            const float Aki_imag2 = -(((const float *)A)[2 * ((k+2) * lda + i) + 1]);
            const float Akj_real2 = (((const float *)A)[2 * ((k+2) * lda + j)]);
            const float Akj_imag2 = (((const float *)A)[2 * ((k+2) * lda + j) + 1]);

            const float Aki_real3 = (((const float *)A)[2 * ((k+3) * lda + i)]);
            const float Aki_imag3 = -(((const float *)A)[2 * ((k+3) * lda + i) + 1]);
            const float Akj_real3 = (((const float *)A)[2 * ((k+3) * lda + j)]);
            const float Akj_imag3 = (((const float *)A)[2 * ((k+3) * lda + j) + 1]);

            temp_real += Aki_real0 * Akj_real0 - Aki_imag0 * Akj_imag0;
            temp_imag += Aki_real0 * Akj_imag0 + Aki_imag0 * Akj_real0;

            temp_real += Aki_real1 * Akj_real1 - Aki_imag1 * Akj_imag1;
            temp_imag += Aki_real1 * Akj_imag1 + Aki_imag1 * Akj_real1;

            temp_real += Aki_real2 * Akj_real2 - Aki_imag2 * Akj_imag2;
            temp_imag += Aki_real2 * Akj_imag2 + Aki_imag2 * Akj_real2;

            temp_real += Aki_real3 * Akj_real3 - Aki_imag3 * Akj_imag3;
            temp_imag += Aki_real3 * Akj_imag3 + Aki_imag3 * Akj_real3;

            k += 4;
        }
        for (; k < K; k++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = -(((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
