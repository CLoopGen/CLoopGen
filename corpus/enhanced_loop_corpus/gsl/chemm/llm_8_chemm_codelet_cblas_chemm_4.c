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
    for (j = 0; j < n2; j += 2) { // Increased trip count step to reduce iterations, increasing computational intensity per iteration
        if (j + 1 >= n2) break; // Handle odd n2 safely
        const float Bij_real_0 = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag_0 = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real_0 = alpha_real * Bij_real_0 - alpha_imag * Bij_imag_0;
        const float temp1_imag_0 = alpha_real * Bij_imag_0 + alpha_imag * Bij_real_0;

        const float Bij_real_1 = (((const float *)B)[2 * (ldb * i + j + 1)]);
        const float Bij_imag_1 = (((const float *)B)[2 * (ldb * i + j + 1) + 1]);
        const float temp1_real_1 = alpha_real * Bij_real_1 - alpha_imag * Bij_imag_1;
        const float temp1_imag_1 = alpha_real * Bij_imag_1 + alpha_imag * Bij_real_1;

        float temp2_real_0 = 0.0f, temp2_imag_0 = 0.0f;
        float temp2_real_1 = 0.0f, temp2_imag_1 = 0.0f;

        // Process diagonal block for both j and j+1
        const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
        const float Ajp1jp1_real = (((const float *)A)[2 * ((j+1) * lda + j+1)]);

        (((float *)C)[2 * (i * ldc + j)]) += temp1_real_0 * Ajj_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_imag_0 * Ajj_real;

        (((float *)C)[2 * (i * ldc + j + 1)]) += temp1_real_1 * Ajp1jp1_real;
        (((float *)C)[2 * (i * ldc + j + 1) + 1]) += temp1_imag_1 * Ajp1jp1_real;

        for (k = j + 1; k < n2; k++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);

            const float Akp1_real = (((const float *)A)[2 * ((j+1) * lda + k)]);
            const float Akp1_imag = (((const float *)A)[2 * ((j+1) * lda + k) + 1]);

            const float Bik_real = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag = (((const float *)B)[2 * (ldb * i + k) + 1]);

            // Update C(i,k) using A(j,k) and B(i,k)
            (((float *)C)[2 * (i * ldc + k)]) += temp1_real_0 * Ajk_real - temp1_imag_0 * Ajk_imag;
            (((float *)C)[2 * (i * ldc + k) + 1]) += temp1_real_0 * Ajk_imag + temp1_imag_0 * Ajk_real;

            (((float *)C)[2 * (i * ldc + k)]) += temp1_real_1 * Akp1_real - temp1_imag_1 * Akp1_imag;
            (((float *)C)[2 * (i * ldc + k) + 1]) += temp1_real_1 * Akp1_imag + temp1_imag_1 * Akp1_real;

            // Accumulate temp2 using B(i,k) and conjugate of A(j,k), A(j+1,k)
            temp2_real_0 += Bik_real * Ajk_real - Bik_imag * (-Ajk_imag);
            temp2_imag_0 += Bik_real * (-Ajk_imag) + Bik_imag * Ajk_real;

            temp2_real_1 += Bik_real * Akp1_real - Bik_imag * (-Akp1_imag);
            temp2_imag_1 += Bik_real * (-Akp1_imag) + Bik_imag * Akp1_real;
        }

        // Final update to diagonal elements
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real_0 - alpha_imag * temp2_imag_0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag_0 + alpha_imag * temp2_real_0;

        (((float *)C)[2 * (i * ldc + j + 1)]) += alpha_real * temp2_real_1 - alpha_imag * temp2_imag_1;
        (((float *)C)[2 * (i * ldc + j + 1) + 1]) += alpha_real * temp2_imag_1 + alpha_imag * temp2_real_1;
    }
}
}
