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
    for (j = 0; j < n2; j++) {
        const double *B_row = &((const double *)B)[2 * ldb * i];
        const double Bij_real = B_row[2 * j];
        const double Bij_imag = B_row[2 * j + 1];
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        const double *A_row = &((const double *)A)[2 * lda * j];
        double *C_row = &((double *)C)[2 * ldc * i];
        for (k = 0; k < j; k++) {
            const double Ajk_real = A_row[2 * k];
            const double Ajk_imag = A_row[2 * k + 1];
            const double Bik_real = B_row[2 * k];
            const double Bik_imag = B_row[2 * k + 1];
            C_row[2 * k] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            C_row[2 * k + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        const double Ajj_real = A_row[2 * j];
        const double Ajj_imag = A_row[2 * j + 1];
        C_row[2 * j] += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        C_row[2 * j + 1] += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
        C_row[2 * j] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        C_row[2 * j + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
