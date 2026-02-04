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
for (i = 0; i < N; i += 2) {
    for (j = 0; j <= i; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        if (i + 1 < N) {
            double temp_real_i1 = 0., temp_imag_i1 = 0.;
            for (k = 0; k < K; k++) {
                const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
                const double Aki_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
                const double Aki1_real = (((const double *)A)[2 * (k * lda + i + 1)]);
                const double Aki1_imag = -(((const double *)A)[2 * (k * lda + i + 1) + 1]);
                const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
                const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);

                temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
                temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;

                temp_real_i1 += Aki1_real * Akj_real - Aki1_imag * Akj_imag;
                temp_imag_i1 += Aki1_real * Akj_imag + Aki1_imag * Akj_real;
            }
            (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
            (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
            (((double *)C)[2 * ((i + 1) * ldc + j)]) += alpha * temp_real_i1;
            (((double *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha * temp_imag_i1;
        } else {
            for (k = 0; k < K; k++) {
                const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
                const double Aki_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
                const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
                const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
                temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
                temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
            }
            (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
            (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
        }
    }
}
}
