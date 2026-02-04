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
        const int b_idx_base = 2 * (ldb * i + j);
        const float Bij_real = ((const float *)B)[b_idx_base];
        const float Bij_imag = ((const float *)B)[b_idx_base + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;

        const int a_jj_idx = 2 * (j * lda + j);
        const float Ajj_real = ((const float *)A)[a_jj_idx];
        const float Ajj_imag = ((const float *)A)[a_jj_idx + 1];
        const int c_ij_idx = 2 * (i * ldc + j);
        ((float *)C)[c_ij_idx] += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        ((float *)C)[c_ij_idx + 1] += temp1_real * Ajj_imag + temp1_imag * Ajj_real;

        for (k = j + 1; k < n2; k++) {
            const int a_jk_idx = 2 * (j * lda + k);
            const float Ajk_real = ((const float *)A)[a_jk_idx];
            const float Ajk_imag = ((const float *)A)[a_jk_idx + 1];

            const int b_ik_idx = 2 * (ldb * i + k);
            const float Bik_real = ((const float *)B)[b_ik_idx];
            const float Bik_imag = ((const float *)B)[b_ik_idx + 1];

            const int c_ik_idx = 2 * (i * ldc + k);
            ((float *)C)[c_ik_idx] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            ((float *)C)[c_ik_idx + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        ((float *)C)[c_ij_idx] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[c_ij_idx + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
