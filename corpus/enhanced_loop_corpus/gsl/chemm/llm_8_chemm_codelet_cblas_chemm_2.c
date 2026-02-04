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
for (i = 0; i < n1; i += 2) {
    if (i + 1 >= n1) continue;
    for (j = 0; j < n2; j++) {
        const float Bij_real0 = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag0 = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real0 = alpha_real * Bij_real0 - alpha_imag * Bij_imag0;
        const float temp1_imag0 = alpha_real * Bij_imag0 + alpha_imag * Bij_real0;
        const float Bij_real1 = (((const float *)B)[2 * (ldb * (i+1) + j)]);
        const float Bij_imag1 = (((const float *)B)[2 * (ldb * (i+1) + j) + 1]);
        const float temp1_real1 = alpha_real * Bij_real1 - alpha_imag * Bij_imag1;
        const float temp1_imag1 = alpha_real * Bij_imag1 + alpha_imag * Bij_real1;
        float temp2_real0 = 0.0f, temp2_real1 = 0.0f;
        float temp2_imag0 = 0.0f, temp2_imag1 = 0.0f;
        {
            const float Aii_real0 = (((const float *)A)[2 * (i * lda + i)]);
            const float Aii_real1 = (((const float *)A)[2 * ((i+1) * lda + (i+1))]);
            (((float *)C)[2 * (i * ldc + j)]) += temp1_real0 * Aii_real0;
            (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_imag0 * Aii_real0;
            (((float *)C)[2 * ((i+1) * ldc + j)]) += temp1_real1 * Aii_real1;
            (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += temp1_imag1 * Aii_real1;
        }
        for (k = i + 1; k < n1; k++) {
            const float Aik_real0 = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag0 = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Akp1k_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
            const float Akp1k_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);
            (((float *)C)[2 * (k * ldc + j)]) += Aik_real0 * temp1_real0 - (-Aik_imag0) * temp1_imag0;
            (((float *)C)[2 * (k * ldc + j) + 1]) += Aik_real0 * temp1_imag0 + (-Aik_imag0) * temp1_real0;
            (((float *)C)[2 * (k * ldc + j)]) += Akp1k_real * temp1_real1 - (-Akp1k_imag) * temp1_imag1;
            (((float *)C)[2 * (k * ldc + j) + 1]) += Akp1k_real * temp1_imag1 + (-Akp1k_imag) * temp1_real1;
            temp2_real0 += Aik_real0 * Bkj_real - Aik_imag0 * Bkj_imag;
            temp2_imag0 += Aik_real0 * Bkj_imag + Aik_imag0 * Bkj_real;
            temp2_real1 += Akp1k_real * Bkj_real - Akp1k_imag * Bkj_imag;
            temp2_imag1 += Akp1k_real * Bkj_imag + Akp1k_imag * Bkj_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real0 - alpha_imag * temp2_imag0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag0 + alpha_imag * temp2_real0;
        (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp2_real1 - alpha_imag * temp2_imag1;
        (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp2_imag1 + alpha_imag * temp2_real1;
    }
}
}
