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
    const int i_ldb_base = ldb * i;
    const int i_ldc_base = ldc * i;
    for (j = 0; j < n2; j++) {
        const int b_offset = 2 * (i_ldb_base + j);
        const float Bij_real = ((const float *)B)[b_offset];
        const float Bij_imag = ((const float *)B)[b_offset + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;

        const int a_j_base = j * lda;
        const int a_jj_offset = 2 * (a_j_base + j);
        const float Ajj_real = ((const float *)A)[a_jj_offset];
        const float Ajj_imag = ((const float *)A)[a_jj_offset + 1];
        const int c_ij_offset = 2 * (i_ldc_base + j);
        ((float *)C)[c_ij_offset] += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        ((float *)C)[c_ij_offset + 1] += temp1_real * Ajj_imag + temp1_imag * Ajj_real;

        for (k = j + 1; k < n2; k++) {
            const int a_jk_offset = 2 * (a_j_base + k);
            const float Ajk_real = ((const float *)A)[a_jk_offset];
            const float Ajk_imag = ((const float *)A)[a_jk_offset + 1];

            const int b_ik_offset = 2 * (i_ldb_base + k);
            const float Bik_real = ((const float *)B)[b_ik_offset];
            const float Bik_imag = ((const float *)B)[b_ik_offset + 1];

            const int c_ik_offset = 2 * (i_ldc_base + k);
            ((float *)C)[c_ik_offset] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            ((float *)C)[c_ik_offset + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        ((float *)C)[c_ij_offset] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[c_ij_offset + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
