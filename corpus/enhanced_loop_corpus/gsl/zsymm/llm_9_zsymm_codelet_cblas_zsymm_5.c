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
for (i = 0; i < n1; i += 2) {
    if (i + 1 >= n1) continue;
    for (j = 0; j < n2; j++) {
        const double Bij0_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij0_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double Bij1_real = (((const double *)B)[2 * (ldb * (i+1) + j)]);
        const double Bij1_imag = (((const double *)B)[2 * (ldb * (i+1) + j) + 1]);

        const double temp1a_real = alpha_real * Bij0_real - alpha_imag * Bij0_imag;
        const double temp1a_imag = alpha_real * Bij0_imag + alpha_imag * Bij0_real;
        const double temp1b_real = alpha_real * Bij1_real - alpha_imag * Bij1_imag;
        const double temp1b_imag = alpha_real * Bij1_imag + alpha_imag * Bij1_real;

        double temp2a_real = 0., temp2a_imag = 0.;
        double temp2b_real = 0., temp2b_imag = 0.;

        for (k = 0; k < j; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);

            const double Bik0_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik0_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
            const double Bik1_real = (((const double *)B)[2 * (ldb * (i+1) + k)]);
            const double Bik1_imag = (((const double *)B)[2 * (ldb * (i+1) + k) + 1]);

            const double prod_real = temp1a_real * Ajk_real - temp1a_imag * Ajk_imag;
            const double prod_imag = temp1a_real * Ajk_imag + temp1a_imag * Ajk_real;

            (((double *)C)[2 * (i * ldc + k)]) += prod_real;
            (((double *)C)[2 * (i * ldc + k) + 1]) += prod_imag;

            (((double *)C)[2 * ((i+1) * ldc + k)]) += temp1b_real * Ajk_real - temp1b_imag * Ajk_imag;
            (((double *)C)[2 * ((i+1) * ldc + k) + 1]) += temp1b_real * Ajk_imag + temp1b_imag * Ajk_real;

            temp2a_real += Bik0_real * Ajk_real - Bik0_imag * Ajk_imag;
            temp2a_imag += Bik0_real * Ajk_imag + Bik0_imag * Ajk_real;
            temp2b_real += Bik1_real * Ajk_real - Bik1_imag * Ajk_imag;
            temp2b_imag += Bik1_real * Ajk_imag + Bik1_imag * Ajk_real;
        }

        const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
        const double Ajj_imag = (((const double *)A)[2 * (j * lda + j) + 1]);

        (((double *)C)[2 * (i * ldc + j)]) += temp1a_real * Ajj_real - temp1a_imag * Ajj_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp1a_real * Ajj_imag + temp1a_imag * Ajj_real;
        (((double *)C)[2 * ((i+1) * ldc + j)]) += temp1b_real * Ajj_real - temp1b_imag * Ajj_imag;
        (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += temp1b_real * Ajj_imag + temp1b_imag * Ajj_real;

        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2a_real - alpha_imag * temp2a_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2a_imag + alpha_imag * temp2a_real;
        (((double *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp2b_real - alpha_imag * temp2b_imag;
        (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp2b_imag + alpha_imag * temp2b_real;
    }
}
for (; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        for (k = 0; k < j; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        {
            const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
            const double Ajj_imag = (((const double *)A)[2 * (j * lda + j) + 1]);
            (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
