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
    float temp_acc_real[64], temp_acc_imag[64];
    for (j = 0; j < n2 && j < 64; j++) {
        temp_acc_real[j] = 0.0f;
        temp_acc_imag[j] = 0.0f;
    }
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        for (k = 0; k < i; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);
            float c_update_real = Aik_real * temp1_real + Aik_imag * temp1_imag;
            float c_update_imag = Aik_real * temp1_imag - Aik_imag * temp1_real;
            (((float *)C)[2 * (k * ldc + j)]) += c_update_real;
            (((float *)C)[2 * (k * ldc + j) + 1]) += c_update_imag;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
            temp_acc_real[j % 64] += temp1_real * Aii_real;
            temp_acc_imag[j % 64] += temp1_imag * Aii_real;
        }
        temp_acc_real[j % 64] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        temp_acc_imag[j % 64] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
    for (j = 0; j < n2; j++) {
        if (j % 64 == 0 && j > 0) {
            for (int jj = j - 64; jj < j; jj++) {
                (((float *)C)[2 * (i * ldc + jj)]) += temp_acc_real[jj % 64];
                (((float *)C)[2 * (i * ldc + jj) + 1]) += temp_acc_imag[jj % 64];
                temp_acc_real[jj % 64] = 0.0f;
                temp_acc_imag[jj % 64] = 0.0f;
            }
        }
    }
    for (int jj = ((n2 - 1) / 64) * 64; jj < n2; jj++) {
        (((float *)C)[2 * (i * ldc + jj)]) += temp_acc_real[jj % 64];
        (((float *)C)[2 * (i * ldc + jj) + 1]) += temp_acc_imag[jj % 64];
    }
}
}
