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
        const ptrdiff_t bj_offset = 2 * (ptrdiff_t)ldb * i + 2 * j;
        const double Bij_real = ((const double*)B)[bj_offset];
        const double Bij_imag = ((const double*)B)[bj_offset + 1];
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.0;
        double temp2_imag = 0.0;
        {
            const ptrdiff_t aii_offset = 2 * (ptrdiff_t)lda * i + 2 * i;
            const double Aii_real = ((const double*)A)[aii_offset];
            const double Aii_imag = ((const double*)A)[aii_offset + 1];
            const ptrdiff_t cij_offset = 2 * (ptrdiff_t)ldc * i + 2 * j;
            ((double*)C)[cij_offset] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            ((double*)C)[cij_offset + 1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        for (k = i + 1; k < n1; k++) {
            const ptrdiff_t aik_offset = 2 * (ptrdiff_t)lda * i + 2 * k;
            const double Aik_real = ((const double*)A)[aik_offset];
            const double Aik_imag = ((const double*)A)[aik_offset + 1];
            const ptrdiff_t bkj_offset = 2 * (ptrdiff_t)ldb * k + 2 * j;
            const double Bkj_real = ((const double*)B)[bkj_offset];
            const double Bkj_imag = ((const double*)B)[bkj_offset + 1];
            const ptrdiff_t ckj_offset = 2 * (ptrdiff_t)ldc * k + 2 * j;
            ((double*)C)[ckj_offset] += Aik_real * temp1_real - Aik_imag * temp1_imag;
            ((double*)C)[ckj_offset + 1] += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        const ptrdiff_t cij_final_offset = 2 * (ptrdiff_t)ldc * i + 2 * j;
        ((double*)C)[cij_final_offset] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double*)C)[cij_final_offset + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
