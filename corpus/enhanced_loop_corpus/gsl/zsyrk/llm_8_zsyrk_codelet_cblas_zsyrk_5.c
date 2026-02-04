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
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        double temp_real_0 = 0., temp_real_1 = 0.;
        double temp_imag_0 = 0., temp_imag_1 = 0.;
        for (k = 0; k < K; k++) {
            const double Aki0_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki0_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real_0 += Aki0_real * Akj_real - Aki0_imag * Akj_imag;
            temp_imag_0 += Aki0_real * Akj_imag + Aki0_imag * Akj_real;

            if (i + 1 < N) {
                const double Aki1_real = (((const double *)A)[2 * (k * lda + i + 1)]);
                const double Aki1_imag = (((const double *)A)[2 * (k * lda + i + 1) + 1]);
                temp_real_1 += Aki1_real * Akj_real - Aki1_imag * Akj_imag;
                temp_imag_1 += Aki1_real * Akj_imag + Aki1_imag * Akj_real;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real_0 - alpha_imag * temp_imag_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag_0 + alpha_imag * temp_real_0;

        if (i + 1 < N) {
            (((double *)C)[2 * ((i + 1) * ldc + j)]) += alpha_real * temp_real_1 - alpha_imag * temp_imag_1;
            (((double *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha_real * temp_imag_1 + alpha_imag * temp_real_1;
        }
    }
}
}
