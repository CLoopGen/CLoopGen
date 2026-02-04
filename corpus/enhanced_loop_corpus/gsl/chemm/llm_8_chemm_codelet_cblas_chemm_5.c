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
    for (j = 0; j < n2; j += 2) { // Increase loop stride to reduce trip count and adjust computational intensity
        if (j + 1 >= n2) break;
        const float Bij_real0 = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag0 = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real0 = alpha_real * Bij_real0 - alpha_imag * Bij_imag0;
        const float temp1_imag0 = alpha_real * Bij_imag0 + alpha_imag * Bij_real0;

        const float Bij_real1 = (((const float *)B)[2 * (ldb * i + j + 1)]);
        const float Bij_imag1 = (((const float *)B)[2 * (ldb * i + j + 1) + 1]);
        const float temp1_real1 = alpha_real * Bij_real1 - alpha_imag * Bij_imag1;
        const float temp1_imag1 = alpha_real * Bij_imag1 + alpha_imag * Bij_real1;

        float temp2_real0 = 0., temp2_imag0 = 0.;
        float temp2_real1 = 0., temp2_imag1 = 0.;

        for (k = 0; k < j + 1; k++) { // Adjusted upper bound to maintain dependencies
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Ajk1_real = (((const float *)A)[2 * ((j + 1) * lda + k)]);
            const float Ajk1_imag = (((const float *)A)[2 * ((j + 1) * lda + k) + 1]);

            const float Bik_real0 = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag0 = (((const float *)B)[2 * (ldb * i + k) + 1]);
            const float Bik_real1 = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag1 = (((const float *)B)[2 * (ldb * i + k) + 1]);

            // Update C for column j
            (((float *)C)[2 * (i * ldc + k)]) += temp1_real0 * Ajk_real - temp1_imag0 * Ajk_imag;
            (((float *)C)[2 * (i * ldc + k) + 1]) += temp1_real0 * Ajk_imag + temp1_imag0 * Ajk_real;

            // Update C for column j+1
            (((float *)C)[2 * (i * ldc + k)]) += temp1_real1 * Ajk1_real - temp1_imag1 * Ajk1_imag;
            (((float *)C)[2 * (i * ldc + k) + 1]) += temp1_real1 * Ajk1_imag + temp1_imag1 * Ajk1_real;

            // Accumulate temp2 for both columns
            temp2_real0 += Bik_real0 * Ajk_real - Bik_imag0 * (-Ajk_imag);
            temp2_imag0 += Bik_real0 * (-Ajk_imag) + Bik_imag0 * Ajk_real;

            temp2_real1 += Bik_real1 * Ajk1_real - Bik_imag1 * (-Ajk1_imag);
            temp2_imag1 += Bik_real1 * (-Ajk1_imag) + Bik_imag1 * Ajk1_real;
        }

        // Apply diagonal update for j
        const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
        (((float *)C)[2 * (i * ldc + j)]) += temp1_real0 * Ajj_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_imag0 * Ajj_real;

        // Apply diagonal update for j+1
        const float Ajj1_real = (((const float *)A)[2 * ((j + 1) * lda + (j + 1))]);
        (((float *)C)[2 * (i * ldc + j + 1)]) += temp1_real1 * Ajj1_real;
        (((float *)C)[2 * (i * ldc + j + 1) + 1]) += temp1_imag1 * Ajj1_real;

        // Final accumulation with alpha for both columns
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real0 - alpha_imag * temp2_imag0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag0 + alpha_imag * temp2_real0;

        (((float *)C)[2 * (i * ldc + j + 1)]) += alpha_real * temp2_real1 - alpha_imag * temp2_imag1;
        (((float *)C)[2 * (i * ldc + j + 1) + 1]) += alpha_real * temp2_imag1 + alpha_imag * temp2_real1;
    }
}
}
