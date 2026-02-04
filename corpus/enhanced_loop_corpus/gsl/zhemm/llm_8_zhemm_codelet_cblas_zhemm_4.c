#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j += 2) {
        if (j + 1 >= n2) break;
        const double Bij_real0 = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag0 = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real0 = alpha_real * Bij_real0 - alpha_imag * Bij_imag0;
        const double temp1_imag0 = alpha_real * Bij_imag0 + alpha_imag * Bij_real0;
        const double Bij_real1 = (((const double *)B)[2 * (ldb * i + j + 1)]);
        const double Bij_imag1 = (((const double *)B)[2 * (ldb * i + j + 1) + 1]);
        const double temp1_real1 = alpha_real * Bij_real1 - alpha_imag * Bij_imag1;
        const double temp1_imag1 = alpha_real * Bij_imag1 + alpha_imag * Bij_real1;
        double temp2_real0 = 0.;
        double temp2_imag0 = 0.;
        double temp2_real1 = 0.;
        double temp2_imag1 = 0.;
        {
            const double Ajj_real0 = (((const double *)A)[2 * (j * lda + j)]);
            (((double *)C)[2 * (i * ldc + j)]) += temp1_real0 * Ajj_real0;
            (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_imag0 * Ajj_real0;
            const double Ajj_real1 = (((const double *)A)[2 * ((j+1) * lda + j+1)]);
            (((double *)C)[2 * (i * ldc + j + 1)]) += temp1_real1 * Ajj_real1;
            (((double *)C)[2 * (i * ldc + j + 1) + 1]) += temp1_imag1 * Ajj_real1;
        }
        for (k = j + 1; k < n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real0 = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag0 = (((const double *)B)[2 * (ldb * i + k) + 1]);
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real0 * Ajk_real - temp1_imag0 * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real0 * Ajk_imag + temp1_imag0 * Ajk_real;
            temp2_real0 += Bik_real0 * Ajk_real - Bik_imag0 * (-Ajk_imag);
            temp2_imag0 += Bik_real0 * (-Ajk_imag) + Bik_imag0 * Ajk_real;

            const double Ajk2_real = (((const double *)A)[2 * ((j+1) * lda + k)]);
            const double Ajk2_imag = (((const double *)A)[2 * ((j+1) * lda + k) + 1]);
            const double Bik_real1 = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag1 = (((const double *)B)[2 * (ldb * i + k) + 1]);
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real1 * Ajk2_real - temp1_imag1 * Ajk2_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real1 * Ajk2_imag + temp1_imag1 * Ajk2_real;
            temp2_real1 += Bik_real1 * Ajk2_real - Bik_imag1 * (-Ajk2_imag);
            temp2_imag1 += Bik_real1 * (-Ajk2_imag) + Bik_imag1 * Ajk2_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real0 - alpha_imag * temp2_imag0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag0 + alpha_imag * temp2_real0;
        (((double *)C)[2 * (i * ldc + j + 1)]) += alpha_real * temp2_real1 - alpha_imag * temp2_imag1;
        (((double *)C)[2 * (i * ldc + j + 1) + 1]) += alpha_real * temp2_imag1 + alpha_imag * temp2_real1;
    }
}
}
