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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        const int B_row_offset = ldb * i;
        const int A_row_base = j * lda;
        const int C_row_offset = i * ldc;
        for (k = 0; k < j; k++) {
            const int A_col_offset = 2 * (A_row_base + k);
            const int B_col_offset = 2 * (B_row_offset + k);
            const int C_col_offset = 2 * (C_row_offset + k);
            const float Ajk_real = ((const float *)A)[A_col_offset];
            const float Ajk_imag = ((const float *)A)[A_col_offset + 1];
            const float Bik_real = ((const float *)B)[B_col_offset];
            const float Bik_imag = ((const float *)B)[B_col_offset + 1];
            ((float *)C)[C_col_offset] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            ((float *)C)[C_col_offset + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        {
            const int A_diag_offset = 2 * (A_row_base + j);
            const int C_jj_offset = 2 * (C_row_offset + j);
            const float Ajj_real = ((const float *)A)[A_diag_offset];
            const float Ajj_imag = ((const float *)A)[A_diag_offset + 1];
            ((float *)C)[C_jj_offset] += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            ((float *)C)[C_jj_offset + 1] += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
        }
        const int C_jj_write_offset = 2 * (i * ldc + j);
        ((float *)C)[C_jj_write_offset] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[C_jj_write_offset + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
