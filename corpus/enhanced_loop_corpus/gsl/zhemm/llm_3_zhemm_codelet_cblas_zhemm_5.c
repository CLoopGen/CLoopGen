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
for (j = 0; j < n2; j++) {
    const double *A_j = &((const double *)A)[2 * lda * j];
    const double Ajj_real = A_j[2 * j];
    for (i = 0; i < n1; i++) {
        const double *B_i = &((const double *)B)[2 * ldb * i];
        const double Bij_real = B_i[2 * j];
        const double Bij_imag = B_i[2 * j + 1];
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.0;
        double temp2_imag = 0.0;
        double *C_i = &((double *)C)[2 * ldc * i];
        for (k = 0; k < j; k++) {
            const double Ajk_real = A_j[2 * k];
            const double Ajk_imag = A_j[2 * k + 1];
            const double Bik_real = B_i[2 * k];
            const double Bik_imag = B_i[2 * k + 1];
            const double product_real = temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            const double product_imag = temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            C_i[2 * k] += product_real;
            C_i[2 * k + 1] += product_imag;
            temp2_real += Bik_real * Ajk_real + Bik_imag * Ajk_imag;
            temp2_imag += Bik_imag * Ajk_real - Bik_real * Ajk_imag;
        }
        C_i[2 * j] += temp1_real * Ajj_real;
        C_i[2 * j + 1] += temp1_imag * Ajj_real;
        C_i[2 * j] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        C_i[2 * j + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
