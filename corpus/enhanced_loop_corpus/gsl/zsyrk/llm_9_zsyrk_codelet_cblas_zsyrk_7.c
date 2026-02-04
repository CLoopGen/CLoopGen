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
for (i = 0; i < N; i += 2) { // Modify outer loop stride to change trip count and data reuse
    for (j = 0; j <= i && i < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        double temp_real_i1 = 0.;
        double temp_imag_i1 = 0.;
        // Perform computation for two consecutive rows (i and i+1) when possible
        const int i_valid = i < N;
        const int i1_valid = (i + 1) < N;
        for (k = 0; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Aki1_real = i1_valid ? (((const double *)A)[2 * (k * lda + i + 1)]) : 0.;
            const double Aki1_imag = i1_valid ? (((const double *)A)[2 * (k * lda + i + 1) + 1]) : 0.;
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);

            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;

            if (i1_valid) {
                temp_real_i1 += Aki1_real * Akj_real - Aki1_imag * Akj_imag;
                temp_imag_i1 += Aki1_real * Akj_imag + Aki1_imag * Akj_real;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
        if (i1_valid && j <= i + 1) {
            (((double *)C)[2 * ((i + 1) * ldc + j)]) += alpha_real * temp_real_i1 - alpha_imag * temp_imag_i1;
            (((double *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha_real * temp_imag_i1 + alpha_imag * temp_real_i1;
        }
    }
}
}
