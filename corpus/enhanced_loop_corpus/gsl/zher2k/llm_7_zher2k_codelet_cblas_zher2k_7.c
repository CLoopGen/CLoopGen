#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  double alpha_real;
extern double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    double diag_sum = 0.;
    for (k = 0; k < K; k++) {
        const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
        const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
        const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
        const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
        double scaled_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
        diag_sum += scaled_real * Bik_real + (alpha_real * Aik_imag + alpha_imag * Aik_real) * Bik_imag;
    }
    (((double *)C)[2 * (i * ldc + i)]) += 2 * diag_sum;
    (((double *)C)[2 * (i * ldc + i) + 1]) = 0.;

    for (j = 0; j < i; j++) {
        double temp_real = 0., temp_imag = 0.;
        for (k = 0; k < K; k += 2) {
            for (int kk = 0; kk < 2 && (k + kk) < K; ++kk) {
                int idx = k + kk;
                const double Aik_real = (((const double *)A)[2 * (i * lda + idx)]);
                const double Aik_imag = (((const double *)A)[2 * (i * lda + idx) + 1]);
                const double Ajk_real = (((const double *)A)[2 * (j * lda + idx)]);
                const double Ajk_imag = (((const double *)A)[2 * (j * lda + idx) + 1]);
                const double Bik_real = (((const double *)B)[2 * (i * ldb + idx)]);
                const double Bik_imag = (((const double *)B)[2 * (i * ldb + idx) + 1]);
                const double Bjk_real = (((const double *)B)[2 * (j * ldb + idx)]);
                const double Bjk_imag = (((const double *)B)[2 * (j * ldb + idx) + 1]);

                const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
                const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
                const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
                const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

                temp_real += temp1_real * Bjk_real + temp1_imag * Bjk_imag;
                temp_real += Bik_real * temp2_real + Bik_imag * temp2_imag;

                temp_imag += temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real;
                temp_imag += Bik_real * (-temp2_imag) + Bik_imag * temp2_real;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp_imag;
    }
}
}
