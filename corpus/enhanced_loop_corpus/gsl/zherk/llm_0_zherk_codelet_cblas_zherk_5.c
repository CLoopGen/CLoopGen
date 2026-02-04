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
    for (j = i; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        k = 0;
        for (; k + 3 < K; k += 4) {
            const double Aik_real0 = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag0 = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real0 = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag0 = -(((const double *)A)[2 * (j * lda + k) + 1]);
            temp_real += Aik_real0 * Ajk_real0 - Aik_imag0 * Ajk_imag0;
            temp_imag += Aik_real0 * Ajk_imag0 + Aik_imag0 * Ajk_real0;

            const double Aik_real1 = (((const double *)A)[2 * (i * lda + k + 1)]);
            const double Aik_imag1 = (((const double *)A)[2 * (i * lda + k + 1) + 1]);
            const double Ajk_real1 = (((const double *)A)[2 * (j * lda + k + 1)]);
            const double Ajk_imag1 = -(((const double *)A)[2 * (j * lda + k + 1) + 1]);
            temp_real += Aik_real1 * Ajk_real1 - Aik_imag1 * Ajk_imag1;
            temp_imag += Aik_real1 * Ajk_imag1 + Aik_imag1 * Ajk_real1;

            const double Aik_real2 = (((const double *)A)[2 * (i * lda + k + 2)]);
            const double Aik_imag2 = (((const double *)A)[2 * (i * lda + k + 2) + 1]);
            const double Ajk_real2 = (((const double *)A)[2 * (j * lda + k + 2)]);
            const double Ajk_imag2 = -(((const double *)A)[2 * (j * lda + k + 2) + 1]);
            temp_real += Aik_real2 * Ajk_real2 - Aik_imag2 * Ajk_imag2;
            temp_imag += Aik_real2 * Ajk_imag2 + Aik_imag2 * Ajk_real2;

            const double Aik_real3 = (((const double *)A)[2 * (i * lda + k + 3)]);
            const double Aik_imag3 = (((const double *)A)[2 * (i * lda + k + 3) + 1]);
            const double Ajk_real3 = (((const double *)A)[2 * (j * lda + k + 3)]);
            const double Ajk_imag3 = -(((const double *)A)[2 * (j * lda + k + 3) + 1]);
            temp_real += Aik_real3 * Ajk_real3 - Aik_imag3 * Ajk_imag3;
            temp_imag += Aik_real3 * Ajk_imag3 + Aik_imag3 * Ajk_real3;
        }
        for (; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = -(((const double *)A)[2 * (j * lda + k) + 1]);
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
