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
        const ptrdiff_t B_offset_ij = 2 * (ldb * i + j);
        const double Bij_real = ((const double*)B)[B_offset_ij];
        const double Bij_imag = ((const double*)B)[B_offset_ij + 1];
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;

        const ptrdiff_t A_offset_jj = 2 * (j * lda + j);
        const ptrdiff_t C_offset_ij = 2 * (i * ldc + j);
        const double Ajj_real = ((const double*)A)[A_offset_jj];
        ((double*)C)[C_offset_ij] += temp1_real * Ajj_real;
        ((double*)C)[C_offset_ij + 1] += temp1_imag * Ajj_real;

        for (k = j + 1; k < n2; k++) {
            const ptrdiff_t A_offset_jk = 2 * (j * lda + k);
            const ptrdiff_t B_offset_ik = 2 * (ldb * i + k);
            const ptrdiff_t C_offset_ik = 2 * (i * ldc + k);

            const double Ajk_real = ((const double*)A)[A_offset_jk];
            const double Ajk_imag = ((const double*)A)[A_offset_jk + 1];
            const double Bik_real = ((const double*)B)[B_offset_ik];
            const double Bik_imag = ((const double*)B)[B_offset_ik + 1];

            ((double*)C)[C_offset_ik] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            ((double*)C)[C_offset_ik + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            temp2_real += Bik_real * Ajk_real + Bik_imag * Ajk_imag;
            temp2_imag += -Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        ((double*)C)[C_offset_ij] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double*)C)[C_offset_ij + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
