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
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        const ptrdiff_t B_offset_ij = 2 * (ldb * i + j);
        const float Bij_real = ((const float *)B)[B_offset_ij];
        const float Bij_imag = ((const float *)B)[B_offset_ij + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;
        {
            const ptrdiff_t A_offset_ii = 2 * (i * lda + i);
            const float Aii_real = ((const float *)A)[A_offset_ii];
            const float Aii_imag = ((const float *)A)[A_offset_ii + 1];
            const ptrdiff_t C_offset_ij = 2 * (i * ldc + j);
            ((float *)C)[C_offset_ij] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            ((float *)C)[C_offset_ij + 1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        for (k = i + 1; k < n1; k++) {
            const ptrdiff_t A_offset_ik = 2 * (i * lda + k);
            const float Aik_real = ((const float *)A)[A_offset_ik];
            const float Aik_imag = ((const float *)A)[A_offset_ik + 1];
            const ptrdiff_t B_offset_kj = 2 * (ldb * k + j);
            const float Bkj_real = ((const float *)B)[B_offset_kj];
            const float Bkj_imag = ((const float *)B)[B_offset_kj + 1];
            const ptrdiff_t C_offset_kj = 2 * (k * ldc + j);
            ((float *)C)[C_offset_kj] += Aik_real * temp1_real - Aik_imag * temp1_imag;
            ((float *)C)[C_offset_kj + 1] += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        const ptrdiff_t C_offset_ij_final = 2 * (i * ldc + j);
        ((float *)C)[C_offset_ij_final] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[C_offset_ij_final + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
