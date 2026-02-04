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
for (i = 0; i < N; i += 2) { // Process two rows at a time to increase computational intensity
    for (j = 0; j <= i; j++) {
        double temp_real0 = 0., temp_real1 = 0.;
        double temp_imag0 = 0., temp_imag1 = 0.;
        for (k = 0; k < K; k++) {
            const double Aik_real0 = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag0 = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Aik_real1 = (((const double *)A)[2 * ((i+1) * lda + k)]);
            const double Aik_imag1 = (((const double *)A)[2 * ((i+1) * lda + k) + 1]);

            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);

            temp_real0 += Aik_real0 * Ajk_real - Aik_imag0 * Ajk_imag;
            temp_imag0 += Aik_real0 * Ajk_imag + Aik_imag0 * Ajk_real;

            if (i + 1 < N) {
                temp_real1 += Aik_real1 * Ajk_real - Aik_imag1 * Ajk_imag;
                temp_imag1 += Aik_real1 * Ajk_imag + Aik_imag1 * Ajk_real;
            }
        }

        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real0 - alpha_imag * temp_imag0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag0 + alpha_imag * temp_real0;

        if (i + 1 < N && j <= i + 1) {
            (((double *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp_real1 - alpha_imag * temp_imag1;
            (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp_imag1 + alpha_imag * temp_real1;
        }
    }
}
}
