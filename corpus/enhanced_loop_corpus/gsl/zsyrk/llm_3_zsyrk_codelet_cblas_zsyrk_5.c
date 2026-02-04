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
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const double *A_base = (const double *)A + 2 * k * lda;
            const double Aki_real = A_base[2 * i];
            const double Aki_imag = A_base[2 * i + 1];
            const double Akj_real = A_base[2 * j];
            const double Akj_imag = A_base[2 * j + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        double *C_base = (double *)C + 2 * (i * ldc + j);
        C_base[0] += alpha_real * temp_real - alpha_imag * temp_imag;
        C_base[1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
