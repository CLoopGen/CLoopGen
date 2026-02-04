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
    for (j = 0; j <= i; j += 2) { // Increase stride to reduce trip count and increase computational intensity per iteration
        double temp_real0 = 0., temp_real1 = 0.;
        double temp_imag0 = 0., temp_imag1 = 0.;
        for (k = 0; k < K; k++) {
            const double Aik_real0 = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag0 = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real0 = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag0 = (((const double *)A)[2 * (j * lda + k) + 1]);
            temp_real0 += Aik_real0 * Ajk_real0 - Aik_imag0 * Ajk_imag0;
            temp_imag0 += Aik_real0 * Ajk_imag0 + Aik_imag0 * Ajk_real0;

            if (j + 1 <= i) { // Prevent out-of-bounds access
                const double Ajk_real1 = (((const double *)A)[2 * ((j+1) * lda + k)]);
                const double Ajk_imag1 = (((const double *)A)[2 * ((j+1) * lda + k) + 1]);
                temp_real1 += Aik_real0 * Ajk_real1 - Aik_imag0 * Ajk_imag1;
                temp_imag1 += Aik_real0 * Ajk_imag1 + Aik_imag0 * Ajk_real1;
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
