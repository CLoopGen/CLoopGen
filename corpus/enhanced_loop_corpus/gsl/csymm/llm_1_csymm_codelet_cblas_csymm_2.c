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
    for (k = i + 1; k < n1; k++) {
        for (j = 0; j < n2; j++) {
            const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
            const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);
            const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            (((float *)C)[2 * (k * ldc + j)]) += Aik_real * temp1_real - Aik_imag * temp1_imag;
            (((float *)C)[2 * (k * ldc + j) + 1]) += Aik_real * temp1_imag + Aik_imag * temp1_real;
            float temp2_inner_real = Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            float temp2_inner_imag = Aik_real * Bkj_imag + Aik_imag * Bkj_real;
            if (k == i + 1) {
                float* Cij_ptr = &(((float *)C)[2 * (i * ldc + j)]);
                const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
                const float Aii_imag = (((const float *)A)[2 * (i * lda + i) + 1]);
                Cij_ptr[0] += temp1_real * Aii_real - temp1_imag * Aii_imag;
                Cij_ptr[1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
            }
            if (k == n1 - 1 && i < n1 - 1) {
                float temp2_accum_real = 0.0f;
                float temp2_accum_imag = 0.0f;
                for (int kk = i + 1; kk < n1; kk++) {
                    const float Akk_j_real = (((const float *)B)[2 * (ldb * kk + j)]);
                    const float Akk_j_imag = (((const float *)B)[2 * (ldb * kk + j) + 1]);
                    const float Aik_k_real = (((const float *)A)[2 * (i * lda + kk)]);
                    const float Aik_k_imag = (((const float *)A)[2 * (i * lda + kk) + 1]);
                    temp2_accum_real += Aik_k_real * Akk_j_real - Aik_k_imag * Akk_j_imag;
                    temp2_accum_imag += Aik_k_real * Akk_j_imag + Aik_k_imag * Akk_j_real;
                }
                float* Cij_ptr = &(((float *)C)[2 * (i * ldc + j)]);
                Cij_ptr[0] += alpha_real * temp2_accum_real - alpha_imag * temp2_accum_imag;
                Cij_ptr[1] += alpha_real * temp2_accum_imag + alpha_imag * temp2_accum_real;
            }
        }
    }
    if (n1 == 1) {
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
}
