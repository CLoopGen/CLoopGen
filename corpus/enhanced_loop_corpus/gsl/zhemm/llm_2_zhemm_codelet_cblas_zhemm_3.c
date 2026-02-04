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
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        for (k = 0; k < i; k++) {
            const int idx_A = 2 * (i * lda + k);
            const double Aik_real = (((const double *)A)[idx_A]);
            const double Aik_imag = (((const double *)A)[idx_A + 1]);
            const int idx_B = 2 * (ldb * k + j);
            const double Bkj_real = (((const double *)B)[idx_B]);
            const double Bkj_imag = (((const double *)B)[idx_B + 1]);
            const int idx_C = 2 * (k * ldc + j);
            ((double *)C)[idx_C] += Aik_real * temp1_real + Aik_imag * temp1_imag;
            ((double *)C)[idx_C + 1] += Aik_real * temp1_imag - Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
            const double Aii_imag = (((const double *)A)[2 * (i * lda + i) + 1]);
            const int idx_C = 2 * (i * ldc + j);
            ((double *)C)[idx_C] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            ((double *)C)[idx_C + 1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        ((double *)C)[2 * (i * ldc + j)] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double *)C)[2 * (i * ldc + j) + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
