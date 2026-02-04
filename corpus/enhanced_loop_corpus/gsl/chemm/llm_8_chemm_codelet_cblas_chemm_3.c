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
    if (i + 1 >= n1) break;
    for (j = 0; j < n2; j++) {
        const float Bij0_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij0_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float Bij1_real = (((const float *)B)[2 * (ldb * (i+1) + j)]);
        const float Bij1_imag = (((const float *)B)[2 * (ldb * (i+1) + j) + 1]);

        const float temp1_0_real = alpha_real * Bij0_real - alpha_imag * Bij0_imag;
        const float temp1_0_imag = alpha_real * Bij0_imag + alpha_imag * Bij0_real;
        const float temp1_1_real = alpha_real * Bij1_real - alpha_imag * Bij1_imag;
        const float temp1_1_imag = alpha_real * Bij1_imag + alpha_imag * Bij1_real;

        float temp2_0_real = 0.0f, temp2_0_imag = 0.0f;
        float temp2_1_real = 0.0f, temp2_1_imag = 0.0f;

        for (k = 0; k < i; k++) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Aik1_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
            const float Aik1_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);

            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);

            const float prod0_real = Aik0_real * temp1_0_real - (-Aik0_imag) * temp1_0_imag;
            const float prod0_imag = Aik0_real * temp1_0_imag + (-Aik0_imag) * temp1_0_real;
            const float prod1_real = Aik1_real * temp1_1_real - (-Aik1_imag) * temp1_1_imag;
            const float prod1_imag = Aik1_real * temp1_1_imag + (-Aik1_imag) * temp1_1_real;

            (((float *)C)[2 * (k * ldc + j)]) += prod0_real;
            (((float *)C)[2 * (k * ldc + j) + 1]) += prod0_imag;
            (((float *)C)[2 * (k * ldc + j)]) += prod1_real;
            (((float *)C)[2 * (k * ldc + j) + 1]) += prod1_imag;

            temp2_0_real += Aik0_real * Bkj_real - Aik0_imag * Bkj_imag;
            temp2_0_imag += Aik0_real * Bkj_imag + Aik0_imag * Bkj_real;
            temp2_1_real += Aik1_real * Bkj_real - Aik1_imag * Bkj_imag;
            temp2_1_imag += Aik1_real * Bkj_imag + Aik1_imag * Bkj_real;
        }

        const float Aii0_real = (((const float *)A)[2 * (i * lda + i)]);
        const float Aii1_real = (((const float *)A)[2 * ((i+1) * lda + (i+1))]);

        (((float *)C)[2 * (i * ldc + j)]) += temp1_0_real * Aii0_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_0_imag * Aii0_real;
        (((float *)C)[2 * ((i+1) * ldc + j)]) += temp1_1_real * Aii1_real;
        (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += temp1_1_imag * Aii1_real;

        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_0_real - alpha_imag * temp2_0_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_0_imag + alpha_imag * temp2_0_real;
        (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp2_1_real - alpha_imag * temp2_1_imag;
        (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp2_1_imag + alpha_imag * temp2_1_real;
    }
}
}
