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
        const double Bij_real_0 = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag_0 = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double Bij_real_1 = (((const double *)B)[2 * (ldb * (i + 1) + j)]);
        const double Bij_imag_1 = (((const double *)B)[2 * (ldb * (i + 1) + j) + 1]);

        const double temp1_real_0 = alpha_real * Bij_real_0 - alpha_imag * Bij_imag_0;
        const double temp1_imag_0 = alpha_real * Bij_imag_0 + alpha_imag * Bij_real_0;
        const double temp1_real_1 = alpha_real * Bij_real_1 - alpha_imag * Bij_imag_1;
        const double temp1_imag_1 = alpha_real * Bij_imag_1 + alpha_imag * Bij_real_1;

        double temp2_real_0 = 0., temp2_real_1 = 0.;
        double temp2_imag_0 = 0., temp2_imag_1 = 0.;

        for (k = 0; k < j; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);

            const double Bik_real_0 = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag_0 = (((const double *)B)[2 * (ldb * i + k) + 1]);
            const double Bik_real_1 = (((const double *)B)[2 * (ldb * (i + 1) + k)]);
            const double Bik_imag_1 = (((const double *)B)[2 * (ldb * (i + 1) + k) + 1]);

            const double update_Cik_real_0 = temp1_real_0 * Ajk_real - temp1_imag_0 * Ajk_imag;
            const double update_Cik_imag_0 = temp1_real_0 * Ajk_imag + temp1_imag_0 * Ajk_real;
            const double update_Cik_real_1 = temp1_real_1 * Ajk_real - temp1_imag_1 * Ajk_imag;
            const double update_Cik_imag_1 = temp1_real_1 * Ajk_imag + temp1_imag_1 * Ajk_real;

            (((double *)C)[2 * (i * ldc + k)]) += update_Cik_real_0;
            (((double *)C)[2 * (i * ldc + k) + 1]) += update_Cik_imag_0;
            (((double *)C)[2 * ((i + 1) * ldc + k)]) += update_Cik_real_1;
            (((double *)C)[2 * ((i + 1) * ldc + k) + 1]) += update_Cik_imag_1;

            temp2_real_0 += Bik_real_0 * Ajk_real - Bik_imag_0 * (-Ajk_imag);
            temp2_imag_0 += Bik_real_0 * (-Ajk_imag) + Bik_imag_0 * Ajk_real;
            temp2_real_1 += Bik_real_1 * Ajk_real - Bik_imag_1 * (-Ajk_imag);
            temp2_imag_1 += Bik_real_1 * (-Ajk_imag) + Bik_imag_1 * Ajk_real;
        }

        const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
        (((double *)C)[2 * (i * ldc + j)]) += temp1_real_0 * Ajj_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_imag_0 * Ajj_real;
        (((double *)C)[2 * ((i + 1) * ldc + j)]) += temp1_real_1 * Ajj_real;
        (((double *)C)[2 * ((i + 1) * ldc + j) + 1]) += temp1_imag_1 * Ajj_real;

        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real_0 - alpha_imag * temp2_imag_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag_0 + alpha_imag * temp2_real_0;
        (((double *)C)[2 * ((i + 1) * ldc + j)]) += alpha_real * temp2_real_1 - alpha_imag * temp2_imag_1;
        (((double *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha_real * temp2_imag_1 + alpha_imag * temp2_real_1;
    }
}
}
