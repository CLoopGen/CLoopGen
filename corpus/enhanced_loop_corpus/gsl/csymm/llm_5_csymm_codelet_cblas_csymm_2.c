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
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);

        float temp1_real, temp1_imag;
        if (alpha_real == 0.0f && alpha_imag == 0.0f) {
            temp1_real = 0.0f;
            temp1_imag = 0.0f;
        } else {
            temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }

        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;

        {
            const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
            const float Aii_imag = (((const float *)A)[2 * (i * lda + i) + 1]);
            float update_real = temp1_real * Aii_real - temp1_imag * Aii_imag;
            float update_imag = temp1_real * Aii_imag + temp1_imag * Aii_real;
            if (!(update_real == 0.0f && update_imag == 0.0f)) {
                (((float *)C)[2 * (i * ldc + j)]) += update_real;
                (((float *)C)[2 * (i * ldc + j) + 1]) += update_imag;
            }
        }

        for (k = i + 1; k < n1; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bkj_real = (((const float *)B)[2 * (ldb * k + j)]);
            const float Bkj_imag = (((const float *)B)[2 * (ldb * k + j) + 1]);

            float term1_real = Aik_real * temp1_real - Aik_imag * temp1_imag;
            float term1_imag = Aik_real * temp1_imag + Aik_imag * temp1_real;
            if (term1_real != 0.0f || term1_imag != 0.0f) {
                (((float *)C)[2 * (k * ldc + j)]) += term1_real;
                (((float *)C)[2 * (k * ldc + j) + 1]) += term1_imag;
            }

            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }

        float final_term_real = alpha_real * temp2_real - alpha_imag * temp2_imag;
        float final_term_imag = alpha_real * temp2_imag + alpha_imag * temp2_real;
        if (final_term_real != 0.0f || final_term_imag != 0.0f) {
            (((float *)C)[2 * (i * ldc + j)]) += final_term_real;
            (((float *)C)[2 * (i * ldc + j) + 1]) += final_term_imag;
        }
    }
}
}
