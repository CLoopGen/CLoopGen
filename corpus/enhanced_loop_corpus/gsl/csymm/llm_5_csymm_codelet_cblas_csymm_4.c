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
        if (alpha_imag == 0.0f && alpha_real != 0.0f) {
            temp1_real = alpha_real * Bij_real;
            temp1_imag = alpha_real * Bij_imag;
        } else {
            temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }

        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;

        {
            const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
            const float Ajj_imag = (((const float *)A)[2 * (j * lda + j) + 1]);
            float product_real = temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            float product_imag = temp1_real * Ajj_imag + temp1_imag * Ajj_real;
            (((float *)C)[2 * (i * ldc + j)]) += product_real;
            (((float *)C)[2 * (i * ldc + j) + 1]) += product_imag;
        }

        for (k = j + 1; k < n2; k++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag = (((const float *)B)[2 * (ldb * i + k) + 1]);

            float c_update_real = temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            float c_update_imag = temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            (((float *)C)[2 * (i * ldc + k)]) += c_update_real;
            (((float *)C)[2 * (i * ldc + k) + 1]) += c_update_imag;

            if (Ajk_real != 0.0f || Ajk_imag != 0.0f) {
                temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
                temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
            }
        }

        float final_update_real = alpha_real * temp2_real - alpha_imag * temp2_imag;
        float final_update_imag = alpha_real * temp2_imag + alpha_imag * temp2_real;
        (((float *)C)[2 * (i * ldc + j)]) += final_update_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += final_update_imag;
    }
}
}
