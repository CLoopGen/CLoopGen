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
    const int B_i_offset = ldb * i;
    const int C_i_offset = i * ldc;
    for (j = 0; j < n2; j++) {
        const int B_ij_index = 2 * (B_i_offset + j);
        const float Bij_real = ((const float *)B)[B_ij_index];
        const float Bij_imag = ((const float *)B)[B_ij_index + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;
        const int A_j_start = j * lda;
        for (k = 0; k < j; k++) {
            const int A_jk_index = 2 * (A_j_start + k);
            const int B_ik_index = 2 * (B_i_offset + k);
            const int C_ik_index = 2 * (C_i_offset + k);
            const float Ajk_real = ((const float *)A)[A_jk_index];
            const float Ajk_imag = ((const float *)A)[A_jk_index + 1];
            const float Bik_real = ((const float *)B)[B_ik_index];
            const float Bik_imag = ((const float *)B)[B_ik_index + 1];
            const float prod_real = temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            const float prod_imag = temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            ((float *)C)[C_ik_index] += prod_real;
            ((float *)C)[C_ik_index + 1] += prod_imag;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        const int A_jj_index = 2 * (A_j_start + j);
        const int C_ij_index = 2 * (C_i_offset + j);
        const float Ajj_real = ((const float *)A)[A_jj_index];
        const float Ajj_imag = ((const float *)A)[A_jj_index + 1];
        ((float *)C)[C_ij_index] += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        ((float *)C)[C_ij_index + 1] += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
        ((float *)C)[C_ij_index] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[C_ij_index + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
