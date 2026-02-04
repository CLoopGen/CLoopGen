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
    for (i = 0; i < n1; i++) {
        const int base_Bij = 2 * (ldb * i + j);
        const double Bij_real = (((const double *)B)[base_Bij]);
        const double Bij_imag = (((const double *)B)[base_Bij + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        for (k = 0; k < i; k++) {
            const int offset_Aik = 2 * (i * lda + k);
            const int offset_Bkj = 2 * (ldb * k + j);
            const double Aik_real = (((const double *)A)[offset_Aik]);
            const double Aik_imag = (((const double *)A)[offset_Aik + 1]);
            const double Bkj_real = (((const double *)B)[offset_Bkj]);
            const double Bkj_imag = (((const double *)B)[offset_Bkj + 1]);
            const int c_index = 2 * (k * ldc + j);
            ((double *)C)[c_index] += Aik_real * temp1_real - Aik_imag * temp1_imag;
            ((double *)C)[c_index + 1] += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        const int a_ii_idx = 2 * (i * lda + i);
        const double Aii_real = (((const double *)A)[a_ii_idx]);
        const double Aii_imag = (((const double *)A)[a_ii_idx + 1]);
        const int c_ij_idx = 2 * (i * ldc + j);
        ((double *)C)[c_ij_idx] += temp1_real * Aii_real - temp1_imag * Aii_imag;
        ((double *)C)[c_ij_idx + 1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        ((double *)C)[c_ij_idx] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double *)C)[c_ij_idx + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
