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
    for (j = 0; j < n2; j += 2) {
        if (j + 1 >= n2) {
            j = n2 - 1;
        }
        float temp1_real[2] = {0}, temp1_imag[2] = {0};
        float temp2_real[2] = {0}, temp2_imag[2] = {0};
        for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
            const float Bij_real = (((const float *)B)[2 * (ldb * i + j + jj)]);
            const float Bij_imag = (((const float *)B)[2 * (ldb * i + j + jj) + 1]);
            temp1_real[jj] = alpha_real * Bij_real - alpha_imag * Bij_imag;
            temp1_imag[jj] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
        {
            const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
            for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
                (((float *)C)[2 * (i * ldc + j + jj)]) += temp1_real[jj] * Aii_real;
                (((float *)C)[2 * (i * ldc + j + jj) + 1]) += temp1_imag[jj] * Aii_real;
            }
        }
        for (k = i + 1; k < n1; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);
            const float Bkp1j_real = (j+1 < n2) ? (((const float *)B)[2 * (ldb * k + j + 1)]) : 0.0f;
            const float Bkp1j_imag = (j+1 < n2) ? (((const float *)B)[2 * (ldb * k + j + 1) + 1]) : 0.0f;
            for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
                const float* temp1_r = &temp1_real[jj];
                const float* temp1_i = &temp1_imag[jj];
                (((float *)C)[2 * (k * ldc + j + jj)]) += Aik_real * (*temp1_r) - (-Aik_imag) * (*temp1_i);
                (((float *)C)[2 * (k * ldc + j + jj) + 1]) += Aik_real * (*temp1_i) + (-Aik_imag) * (*temp1_r);
            }
            temp2_real[0] += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag[0] += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
            if (j+1 < n2) {
                temp2_real[1] += Aik_real * Bkp1j_real - Aik_imag * Bkp1j_imag;
                temp2_imag[1] += Aik_real * Bkp1j_imag + Aik_imag * Bkp1j_real;
            }
        }
        for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
            (((float *)C)[2 * (i * ldc + j + jj)]) += alpha_real * temp2_real[jj] - alpha_imag * temp2_imag[jj];
            (((float *)C)[2 * (i * ldc + j + jj) + 1]) += alpha_real * temp2_imag[jj] + alpha_imag * temp2_real[jj];
        }
        if (j == n2 - 1) break;
    }
}
}
