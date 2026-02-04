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
        const int b_idx_base = 2 * (ldb * i + j);
        const double Bij_real = ((const double *)B)[b_idx_base];
        const double Bij_imag = ((const double *)B)[b_idx_base + 1];
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        {
            const int a_idx_diag = 2 * (j * lda + j);
            const double Ajj_real = ((const double *)A)[a_idx_diag];
            const double Ajj_imag = ((const double *)A)[a_idx_diag + 1];
            const int c_idx_j = 2 * (i * ldc + j);
            ((double *)C)[c_idx_j] += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            ((double *)C)[c_idx_j + 1] += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
        }
        for (k = j + 1; k < n2; k++) {
            const int a_idx = 2 * (j * lda + k);
            const double Ajk_real = ((const double *)A)[a_idx];
            const double Ajk_imag = ((const double *)A)[a_idx + 1];
            const int b_idx_k = 2 * (ldb * i + k);
            const double Bik_real = ((const double *)B)[b_idx_k];
            const double Bik_imag = ((const double *)B)[b_idx_k + 1];
            const int c_idx_k = 2 * (i * ldc + k);
            ((double *)C)[c_idx_k] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            ((double *)C)[c_idx_k + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        const int c_idx_j = 2 * (i * ldc + j);
        ((double *)C)[c_idx_j] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double *)C)[c_idx_j + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
