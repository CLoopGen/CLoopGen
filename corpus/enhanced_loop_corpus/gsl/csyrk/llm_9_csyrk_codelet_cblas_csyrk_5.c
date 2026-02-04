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
    for (j = i; j < N && j < i + 4; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k += 2) {
            const float Aki_real_k0 = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag_k0 = (((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real_k0 = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag_k0 = (((const float *)A)[2 * (k * lda + j) + 1]);

            temp_real += Aki_real_k0 * Akj_real_k0 - Aki_imag_k0 * Akj_imag_k0;
            temp_imag += Aki_real_k0 * Akj_imag_k0 + Aki_imag_k0 * Akj_real_k0;

            if (k + 1 < K) {
                const float Aki_real_k1 = (((const float *)A)[2 * ((k + 1) * lda + i)]);
                const float Aki_imag_k1 = (((const float *)A)[2 * ((k + 1) * lda + i) + 1]);
                const float Akj_real_k1 = (((const float *)A)[2 * ((k + 1) * lda + j)]);
                const float Akj_imag_k1 = (((const float *)A)[2 * ((k + 1) * lda + j) + 1]);

                temp_real += Aki_real_k1 * Akj_real_k1 - Aki_imag_k1 * Akj_imag_k1;
                temp_imag += Aki_real_k1 * Akj_imag_k1 + Aki_imag_k1 * Akj_real_k1;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
