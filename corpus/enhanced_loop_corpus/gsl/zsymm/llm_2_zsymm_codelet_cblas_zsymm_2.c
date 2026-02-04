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
        const int bj_idx = 2 * (ldb * i + j);
        const double Bij_real = ((const double*)B)[bj_idx];
        const double Bij_imag = ((const double*)B)[bj_idx + 1];
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        {
            const int aii_idx = 2 * (i * lda + i);
            const double Aii_real = ((const double*)A)[aii_idx];
            const double Aii_imag = ((const double*)A)[aii_idx + 1];
            const int cij_idx = 2 * (i * ldc + j);
            ((double*)C)[cij_idx] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            ((double*)C)[cij_idx + 1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        for (k = i + 1; k < n1; k++) {
            const int aik_idx = 2 * (i * lda + k);
            const double Aik_real = ((const double*)A)[aik_idx];
            const double Aik_imag = ((const double*)A)[aik_idx + 1];
            const int bkj_idx = 2 * (ldb * k + j);
            const double Bkj_real = ((const double*)B)[bkj_idx];
            const double Bkj_imag = ((const double*)B)[bkj_idx + 1];
            const int ckj_idx = 2 * (k * ldc + j);
            ((double*)C)[ckj_idx] += Aik_real * temp1_real - Aik_imag * temp1_imag;
            ((double*)C)[ckj_idx + 1] += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        const int cij_final_idx = 2 * (i * ldc + j);
        ((double*)C)[cij_final_idx] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double*)C)[cij_final_idx + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
