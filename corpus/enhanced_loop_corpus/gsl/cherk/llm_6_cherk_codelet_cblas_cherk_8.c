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
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        float sum_real = 0.;
        float sum_imag = 0.;
        for (k = 0; k < K; k += 2) {
            const float Aki_real1 = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag1 = -(((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real1 = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag1 = (((const float *)A)[2 * (k * lda + j) + 1]);
            sum_real += Aki_real1 * Akj_real1 - Aki_imag1 * Akj_imag1;
            sum_imag += Aki_real1 * Akj_imag1 + Aki_imag1 * Akj_real1;

            if (k + 1 < K) {
                const float Aki_real2 = (((const float *)A)[2 * ((k+1) * lda + i)]);
                const float Aki_imag2 = -(((const float *)A)[2 * ((k+1) * lda + i) + 1]);
                const float Akj_real2 = (((const float *)A)[2 * ((k+1) * lda + j)]);
                const float Akj_imag2 = (((const float *)A)[2 * ((k+1) * lda + j) + 1]);
                sum_real += Aki_real2 * Akj_real2 - Aki_imag2 * Akj_imag2;
                sum_imag += Aki_real2 * Akj_imag2 + Aki_imag2 * Akj_real2;
            }
        }
        temp_real = sum_real;
        temp_imag = sum_imag;
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
