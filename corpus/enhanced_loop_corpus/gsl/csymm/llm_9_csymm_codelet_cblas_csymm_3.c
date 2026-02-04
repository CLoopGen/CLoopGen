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

        for (k = 0; k < i; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);

            for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
                const float Bkj_real = (((const float *)B)[2 * (ldb * k + j + jj)]);
                const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j + jj) + 1]);

                const float prod_real = Aik_real * temp1_real[jj] - Aik_imag * temp1_imag[jj];
                const float prod_imag = Aik_real * temp1_imag[jj] + Aik_imag * temp1_real[jj];

                (((float *)C)[2 * (k * ldc + j + jj)]) += prod_real;
                (((float *)C)[2 * (k * ldc + j + jj) + 1]) += prod_imag;

                temp2_real[jj] += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
                temp2_imag[jj] += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
            }
        }

        const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
        const float Aii_imag = (((const float *)A)[2 * (i * lda + i) + 1]);

        for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
            (((float *)C)[2 * (i * ldc + j + jj)]) += temp1_real[jj] * Aii_real - temp1_imag[jj] * Aii_imag;
            (((float *)C)[2 * (i * ldc + j + jj) + 1]) += temp1_real[jj] * Aii_imag + temp1_imag[jj] * Aii_real;

            (((float *)C)[2 * (i * ldc + j + jj)]) += alpha_real * temp2_real[jj] - alpha_imag * temp2_imag[jj];
            (((float *)C)[2 * (i * ldc + j + jj) + 1]) += alpha_real * temp2_imag[jj] + alpha_imag * temp2_real[jj];
        }

        if (j + 1 >= n2) break;
    }
}
}
