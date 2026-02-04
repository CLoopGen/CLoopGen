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
    for (j = 0; j < n2; j++) {
        for (int ii = i; ii < i + 2 && ii < n1; ii++) {
            const float Bij_real = (((const float *)B)[2 * (ldb * ii + j)]);
            const float Bij_imag = (((const float *)B)[2 * (ldb * ii + j) + 1]);
            const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
            float temp2_real = 0.;
            float temp2_imag = 0.;
            {
                const float Aii_real = (((const float *)A)[2 * (ii * lda + ii)]);
                const float Aii_imag = (((const float *)A)[2 * (ii * lda + ii) + 1]);
                (((float *)C)[2 * (ii * ldc + j)]) += temp1_real * Aii_real - temp1_imag * Aii_imag;
                (((float *)C)[2 * (ii * ldc + j) + 1]) += temp1_real * Aii_imag + temp1_imag * Aii_real;
            }
            for (k = ii + 1; k < n1; k++) {
                const float Aik_real = (((const float *)A)[2 * (ii * lda + k)]);
                const float Aik_imag = (((const float *)A)[2 * (ii * lda + k) + 1]);
                const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
                const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);
                (((float *)C)[2 * (k * ldc + j)]) += Aik_real * temp1_real - Aik_imag * temp1_imag;
                (((float *)C)[2 * (k * ldc + j) + 1]) += Aik_real * temp1_imag + Aik_imag * temp1_real;
                temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
                temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
            }
            (((float *)C)[2 * (ii * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
            (((float *)C)[2 * (ii * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
        }
    }
}
}
