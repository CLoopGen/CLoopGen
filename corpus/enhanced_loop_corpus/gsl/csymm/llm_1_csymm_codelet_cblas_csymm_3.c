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
    for (k = 0; k < i; k++) {
        const float Aik_real_base = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik_imag_base = (((const float *)A)[2 * (i * lda + k) + 1]);
        for (j = 0; j < n2; j++) {
            const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
            const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
            const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);
            (((float *)C)[2 * (k * ldc + j)]) += Aik_real_base * temp1_real - Aik_imag_base * temp1_imag;
            (((float *)C)[2 * (k * ldc + j) + 1]) += Aik_real_base * temp1_imag + Aik_imag_base * temp1_real;
            float temp2_real = Aik_real_base * Bkj_real - Aik_imag_base * Bkj_imag;
            float temp2_imag = Aik_real_base * Bkj_imag + Aik_imag_base * Bkj_real;
            ((float*)C)[2 * (i * ldc + j)] += alpha_real * temp2_real - alpha_imag * temp2_imag;
            ((float*)C)[2 * (i * ldc + j) + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
        }
    }
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
        const float Aii_imag = (((const float *)A)[2 * (i * lda + i) + 1]);
        (((float *)C)[2 * (i * ldc + j)]) += temp1_real * Aii_real - temp1_imag * Aii_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Aii_imag + temp1_imag * Aii_real;
    }
}
}
