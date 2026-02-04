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
        float sum_real_local = 0.;
        float sum_imag_local = 0.;
        for (k = 0; k < K; k += 2) {
            float prod_real1 = 0., prod_imag1 = 0.;
            float prod_real2 = 0., prod_imag2 = 0.;

            if (k < K) {
                const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
                const float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
                const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
                const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
                prod_real1 = Aki_real * Akj_real - Aki_imag * Akj_imag;
                prod_imag1 = Aki_real * Akj_imag + Aki_imag * Akj_real;
            }

            if (k + 1 < K) {
                const float Aki_real2 = (((const float *)A)[2 * ((k+1) * lda + i)]);
                const float Aki_imag2 = (((const float *)A)[2 * ((k+1) * lda + i) + 1]);
                const float Akj_real2 = (((const float *)A)[2 * ((k+1) * lda + j)]);
                const float Akj_imag2 = (((const float *)A)[2 * ((k+1) * lda + j) + 1]);
                prod_real2 = Aki_real2 * Akj_real2 - Aki_imag2 * Akj_imag2;
                prod_imag2 = Aki_real2 * Akj_imag2 + Aki_imag2 * Akj_real2;
            }

            sum_real_local += prod_real1 + prod_real2;
            sum_imag_local += prod_imag1 + prod_imag2;
        }
        temp_real = sum_real_local;
        temp_imag = sum_imag_local;
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
