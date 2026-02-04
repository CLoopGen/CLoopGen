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
for (i = 0; i < n1; i += 2) { // Increase outer loop stride, reducing total iterations but increasing work per block
    if (i + 1 >= n1) continue; // Skip if not enough rows
    for (j = 0; j < n2; j++) {
        // Load B(i,j) and B(i+1,j)
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;

        const float Bi1j_real = (((const float *)B)[2 * (ldb * (i+1) + j)]);
        const float Bi1j_imag = (((const float *)B)[2 * (ldb * (i+1) + j) + 1]);
        const float temp1_real_i1 = alpha_real * Bi1j_real - alpha_imag * Bi1j_imag;
        const float temp1_imag_i1 = alpha_real * Bi1j_imag + alpha_imag * Bi1j_real;

        float temp2_real = 0.0f, temp2_imag = 0.0f;
        float temp2_real_i1 = 0.0f, temp2_imag_i1 = 0.0f;

        const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
        // Update both C(i,j) and C(i+1,j) with diagonal term
        (((float *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_imag * Ajj_real;

        (((float *)C)[2 * ((i+1) * ldc + j)]) += temp1_real_i1 * Ajj_real;
        (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += temp1_imag_i1 * Ajj_real;

        for (k = j + 1; k < n2; k++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);

            const float Bik_real = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag = (((const float *)B)[2 * (ldb * i + k) + 1]);

            const float Bi1k_real = (((const float *)B)[2 * (ldb * (i+1) + k)]);
            const float Bi1k_imag = (((const float *)B)[2 * (ldb * (i+1) + k) + 1]);

            // Update C(i,k) and C(i+1,k) using A(j,k)
            (((float *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((float *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            (((float *)C)[2 * ((i+1) * ldc + k)]) += temp1_real_i1 * Ajk_real - temp1_imag_i1 * Ajk_imag;
            (((float *)C)[2 * ((i+1) * ldc + k) + 1]) += temp1_real_i1 * Ajk_imag + temp1_imag_i1 * Ajk_real;

            // Accumulate temp2 using B(i,k), B(i+1,k) and conjugate(A(j,k))
            temp2_real += Bik_real * Ajk_real - Bik_imag * (-Ajk_imag);
            temp2_imag += Bik_real * (-Ajk_imag) + Bik_imag * Ajk_real;

            temp2_real_i1 += Bi1k_real * Ajk_real - Bi1k_imag * (-Ajk_imag);
            temp2_imag_i1 += Bi1k_real * (-Ajk_imag) + Bi1k_imag * Ajk_real;
        }

        // Final accumulation into diagonal for both rows
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;

        (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp2_real_i1 - alpha_imag * temp2_imag_i1;
        (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp2_imag_i1 + alpha_imag * temp2_real_i1;
    }
}
}
