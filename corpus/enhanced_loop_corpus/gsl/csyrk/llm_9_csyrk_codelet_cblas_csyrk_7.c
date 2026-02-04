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
    for (j = 0; j <= i && j < K; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        int unroll_factor = 4;
        int k = 0;
        for (; k + unroll_factor <= K; k += unroll_factor) {
            const float Aki0_real = (((const float *)A)[2 * (k     * lda + i)]);
            const float Aki0_imag = (((const float *)A)[2 * (k     * lda + i) + 1]);
            const float Akj0_real = (((const float *)A)[2 * (k     * lda + j)]);
            const float Akj0_imag = (((const float *)A)[2 * (k     * lda + j) + 1]);

            const float Aki1_real = (((const float *)A)[2 * ((k+1) * lda + i)]);
            const float Aki1_imag = (((const float *)A)[2 * ((k+1) * lda + i) + 1]);
            const float Akj1_real = (((const float *)A)[2 * ((k+1) * lda + j)]);
            const float Akj1_imag = (((const float *)A)[2 * ((k+1) * lda + j) + 1]);

            const float Aki2_real = (((const float *)A)[2 * ((k+2) * lda + i)]);
            const float Aki2_imag = (((const float *)A)[2 * ((k+2) * lda + i) + 1]);
            const float Akj2_real = (((const float *)A)[2 * ((k+2) * lda + j)]);
            const float Akj2_imag = (((const float *)A)[2 * ((k+2) * lda + j) + 1]);

            const float Aki3_real = (((const float *)A)[2 * ((k+3) * lda + i)]);
            const float Aki3_imag = (((const float *)A)[2 * ((k+3) * lda + i) + 1]);
            const float Akj3_real = (((const float *)A)[2 * ((k+3) * lda + j)]);
            const float Akj3_imag = (((const float *)A)[2 * ((k+3) * lda + j) + 1]);

            temp_real += Aki0_real * Akj0_real - Aki0_imag * Akj0_imag +
                         Aki1_real * Akj1_real - Aki1_imag * Akj1_imag +
                         Aki2_real * Akj2_real - Aki2_imag * Akj2_imag +
                         Aki3_real * Akj3_real - Aki3_imag * Akj3_imag;

            temp_imag += Aki0_real * Akj0_imag + Aki0_imag * Akj0_real +
                         Aki1_real * Akj1_imag + Aki1_imag * Akj1_real +
                         Aki2_real * Akj2_imag + Aki2_imag * Akj2_real +
                         Aki3_real * Akj3_imag + Aki3_imag * Akj3_real;
        }
        for (; k < K; k++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
