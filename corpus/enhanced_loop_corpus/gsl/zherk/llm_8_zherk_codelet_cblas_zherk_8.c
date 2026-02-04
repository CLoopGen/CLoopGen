#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
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
    for (j = 0; j <= i; j += 2) {
        double temp_real_0 = 0., temp_real_1 = 0.;
        double temp_imag_0 = 0., temp_imag_1 = 0.;
        int k = 0;
        for (; k + 1 < K; k += 2) {
            const double Aki0_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki0_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj0_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj0_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real_0 += Aki0_real * Akj0_real - Aki0_imag * Akj0_imag;
            temp_imag_0 += Aki0_real * Akj0_imag + Aki0_imag * Akj0_real;

            const double Aki1_real = (((const double *)A)[2 * ((k+1) * lda + i)]);
            const double Aki1_imag = -(((const double *)A)[2 * ((k+1) * lda + i) + 1]);
            const double Akj1_real = (((const double *)A)[2 * ((k+1) * lda + j)]);
            const double Akj1_imag = (((const double *)A)[2 * ((k+1) * lda + j) + 1]);
            temp_real_1 += Aki1_real * Akj1_real - Aki1_imag * Akj1_imag;
            temp_imag_1 += Aki1_real * Akj1_imag + Aki1_imag * Akj1_real;
        }
        for (; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real_0 += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag_0 += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        temp_real_0 += temp_real_1;
        temp_imag_0 += temp_imag_1;
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_0;
        if (j + 1 <= i) {
            (((double *)C)[2 * (i * ldc + j + 1)]) += alpha * temp_real_1;
            (((double *)C)[2 * (i * ldc + j + 1) + 1]) += alpha * temp_imag_1;
        }
    }
}
}
