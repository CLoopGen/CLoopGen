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
    double temp_real_j, temp_imag_j;
    for (j = i; j < N; j++) {
        temp_real_j = 0.;
        temp_imag_j = 0.;
        for (k = 0; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real_j += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag_j += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real_j - alpha_imag * temp_imag_j;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag_j + alpha_imag * temp_real_j;
    }
}
}
