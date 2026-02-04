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
    double temp_real_acc = 0.;
    double temp_imag_acc = 0.;

    for (k = 0; k < K; k++) {
        const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
        const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
        const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
        const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);

        const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
        const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;

        temp_real_acc += temp1_real * Bik_real + temp1_imag * Bik_imag;
        temp_imag_acc += temp1_real * (-Bik_imag) + temp1_imag * Bik_real;
    }

    (((double *)C)[2 * (i * ldc + i)]) += 2 * temp_real_acc;
    (((double *)C)[2 * (i * ldc + i) + 1]) = 0.;

    for (j = i + 1; j < N; j++) {
        double temp_real_upper = 0.;
        double temp_imag_upper = 0.;

        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);

            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

            const double prod1_real = temp1_real * Bjk_real - temp1_imag * Bjk_imag;
            const double prod1_imag = temp1_real * Bjk_imag + temp1_imag * Bjk_real;
            const double prod2_real = Bik_real * temp2_real - Bik_imag * temp2_imag;
            const double prod2_imag = Bik_real * temp2_imag + Bik_imag * temp2_real;

            temp_real_upper += prod1_real + prod2_real;
            temp_imag_upper += prod1_imag + prod2_imag;
        }

        const int idx = 2 * (i * ldc + j);
        (((double *)C)[idx]) += temp_real_upper;
        (((double *)C)[idx + 1]) += temp_imag_upper;
    }
}
}
