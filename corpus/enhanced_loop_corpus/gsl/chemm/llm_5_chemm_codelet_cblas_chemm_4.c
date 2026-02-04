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
        if (alpha_imag == 0.0f && alpha_real == 1.0f) {
            temp1_real = Bij_real;
            temp1_imag = Bij_imag;
        } else {
            temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }

        float temp2_real = 0.;
        float temp2_imag = 0.;

        {
            const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
            float *c_ptr = &(((float *)C)[2 * (i * ldc + j)]);
            c_ptr[0] += temp1_real * Ajj_real;
            c_ptr[1] += temp1_imag * Ajj_real;
        }

        for (k = j + 1; k < n2; k++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag = (((const float *)B)[2 * (ldb * i + k) + 1]);

            float *c_k_ptr = &(((float *)C)[2 * (i * ldc + k)]);
            c_k_ptr[0] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            c_k_ptr[1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            if (Ajk_imag != 0.0f) {
                temp2_real += Bik_real * Ajk_real - Bik_imag * (-Ajk_imag);
                temp2_imag += Bik_real * (-Ajk_imag) + Bik_imag * Ajk_real;
            } else {
                temp2_real += Bik_real * Ajk_real;
                temp2_imag += Bik_imag * Ajk_real;
            }
        }

        if (n2 > j + 1) {
            (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
            (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
        }
    }
}
}
