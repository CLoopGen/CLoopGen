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
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j += 2) { // Increase stride to reduce trip count and adjust computational intensity
        double temp_real0 = 0., temp_real1 = 0.;
        double temp_imag0 = 0., temp_imag1 = 0.;
        for (k = 0; k < K; k++) {
            // Unroll inner loop by factor of 2 to increase arithmetic operations per iteration
            const double Aki_real0 = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag0 = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real0 = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag0 = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real0 += Aki_real0 * Akj_real0 - Aki_imag0 * Akj_imag0;
            temp_imag0 += Aki_real0 * Akj_imag0 + Aki_imag0 * Akj_real0;

            if (j + 1 <= i) { // Guard against out-of-bounds access
                const double Aki_real1 = (((const double *)A)[2 * (k * lda + i)]);
                const double Aki_imag1 = (((const double *)A)[2 * (k * lda + i) + 1]);
                const double Akj_real1 = (((const double *)A)[2 * (k * lda + j + 1)]);
                const double Akj_imag1 = (((const double *)A)[2 * (k * lda + j + 1) + 1]);
                temp_real1 += Aki_real1 * Akj_real1 - Aki_imag1 * Akj_imag1;
                temp_imag1 += Aki_real1 * Akj_imag1 + Aki_imag1 * Akj_real1;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real0 - alpha_imag * temp_imag0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag0 + alpha_imag * temp_real0;
        if (j + 1 <= i) {
            (((double *)C)[2 * (i * ldc + j + 1)]) += alpha_real * temp_real1 - alpha_imag * temp_imag1;
            (((double *)C)[2 * (i * ldc + j + 1) + 1]) += alpha_real * temp_imag1 + alpha_imag * temp_real1;
        }
    }
}
}
