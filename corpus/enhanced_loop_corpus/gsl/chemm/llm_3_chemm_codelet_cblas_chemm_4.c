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
    const float *A_row_j = (const float *)A + 2 * lda * j;
    const float *B_col_j = (const float *)B + 2 * ldb * 0 + 2 * j;
    for (k = j + 1; k < n2; k++) {
        const float Ajk_real = A_row_j[2 * k];
        const float Ajk_imag = A_row_j[2 * k + 1];
        for (i = 0; i < n1; i++) {
            const float *B_row_i = (const float *)B + 2 * ldb * i;
            const float Bij_real = B_row_i[2 * j];
            const float Bij_imag = B_row_i[2 * j + 1];
            const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
            float *C_row_i = (float *)C + 2 * ldc * i;
            C_row_i[2 * k] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            C_row_i[2 * k + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
        }
    }
    for (i = 0; i < n1; i++) {
        const float *B_row_i = (const float *)B + 2 * ldb * i;
        const float *C_row_i = (const float *)C + 2 * ldc * i;
        const float Bij_real = B_row_i[2 * j];
        const float Bij_imag = B_row_i[2 * j + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;
        const float Ajj_real = A_row_j[2 * j];
        ((float *)C)[2 * (i * ldc + j)] += temp1_real * Ajj_real;
        ((float *)C)[2 * (i * ldc + j) + 1] += temp1_imag * Ajj_real;
        for (k = j + 1; k < n2; k++) {
            const float *A_row_j = (const float *)A + 2 * lda * j;
            const float Ajk_real = A_row_j[2 * k];
            const float Ajk_imag = A_row_j[2 * k + 1];
            const float Bik_real = B_row_i[2 * k];
            const float Bik_imag = B_row_i[2 * k + 1];
            temp2_real += Bik_real * Ajk_real + Bik_imag * Ajk_imag;
            temp2_imag += (-Bik_real * Ajk_imag) + Bik_imag * Ajk_real;
        }
        ((float *)C)[2 * (i * ldc + j)] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[2 * (i * ldc + j) + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
