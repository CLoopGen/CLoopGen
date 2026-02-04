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
for (i = 0; i < n1; i += 2) { // Process two rows at a time to increase data reuse and arithmetic intensity
    if (i + 1 >= n1) continue;
    for (j = 0; j < n2; j++) {
        const float Bij_real0 = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag0 = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real0 = alpha_real * Bij_real0 - alpha_imag * Bij_imag0;
        const float temp1_imag0 = alpha_real * Bij_imag0 + alpha_imag * Bij_real0;

        const float Bij_real1 = (((const float *)B)[2 * (ldb * (i + 1) + j)]);
        const float Bij_imag1 = (((const float *)B)[2 * (ldb * (i + 1) + j) + 1]);
        const float temp1_real1 = alpha_real * Bij_real1 - alpha_imag * Bij_imag1;
        const float temp1_imag1 = alpha_real * Bij_imag1 + alpha_imag * Bij_real1;

        float temp2_real0 = 0., temp2_imag0 = 0.;
        float temp2_real1 = 0., temp2_imag1 = 0.;

        for (k = 0; k < j; k++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);

            const float Bik_real0 = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag0 = (((const float *)B)[2 * (ldb * i + k) + 1]);
            const float Bik_real1 = (((const float *)B)[2 * (ldb * (i + 1) + k)]);
            const float Bik_imag1 = (((const float *)B)[2 * (ldb * (i + 1) + k) + 1]);

            // Update C for row i and i+1 using same A coefficient
            float update_real = temp1_real0 * Ajk_real - temp1_imag0 * Ajk_imag;
            float update_imag = temp1_real0 * Ajk_imag + temp1_imag0 * Ajk_real;
            (((float *)C)[2 * (i * ldc + k)]) += update_real;
            (((float *)C)[2 * (i * ldc + k) + 1]) += update_imag;

            update_real = temp1_real1 * Ajk_real - temp1_imag1 * Ajk_imag;
            update_imag = temp1_real1 * Ajk_imag + temp1_imag1 * Ajk_real;
            (((float *)C)[2 * ((i + 1) * ldc + k)]) += update_real;
            (((float *)C)[2 * ((i + 1) * ldc + k) + 1]) += update_imag;

            // Accumulate temp2 for both rows
            temp2_real0 += Bik_real0 * Ajk_real - Bik_imag0 * (-Ajk_imag);
            temp2_imag0 += Bik_real0 * (-Ajk_imag) + Bik_imag0 * Ajk_real;

            temp2_real1 += Bik_real1 * Ajk_real - Bik_imag1 * (-Ajk_imag);
            temp2_imag1 += Bik_real1 * (-Ajk_imag) + Bik_imag1 * Ajk_real;
        }

        // Diagonal update for column j
        const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
        (((float *)C)[2 * (i * ldc + j)]) += temp1_real0 * Ajj_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_imag0 * Ajj_real;

        (((float *)C)[2 * ((i + 1) * ldc + j)]) += temp1_real1 * Ajj_real;
        (((float *)C)[2 * ((i + 1) * ldc + j) + 1]) += temp1_imag1 * Ajj_real;

        // Final alpha-weighted update for both rows
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real0 - alpha_imag * temp2_imag0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag0 + alpha_imag * temp2_real0;

        (((float *)C)[2 * ((i + 1) * ldc + j)]) += alpha_real * temp2_real1 - alpha_imag * temp2_imag1;
        (((float *)C)[2 * ((i + 1) * ldc + j) + 1]) += alpha_real * temp2_imag1 + alpha_imag * temp2_real1;
    }
}
}
