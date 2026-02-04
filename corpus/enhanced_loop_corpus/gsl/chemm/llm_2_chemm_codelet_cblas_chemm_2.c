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
        const float *b_ptr = (const float *)B + 2 * ldb * i + 2 * j;
        const float Bij_real = b_ptr[0];
        const float Bij_imag = b_ptr[1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        {
            const float *a_ptr = (const float *)A + 2 * (i * lda + i);
            float *c_ptr = (float *)C + 2 * (i * ldc + j);
            c_ptr[0] += temp1_real * a_ptr[0];
            c_ptr[1] += temp1_imag * a_ptr[0];
        }
        for (k = i + 1; k < n1; k++) {
            const float *a_ik_ptr = (const float *)A + 2 * (i * lda + k);
            const float Aik_real = a_ik_ptr[0];
            const float Aik_imag = a_ik_ptr[1];
            const float *b_kj_ptr = (const float *)B + 2 * (ldb * k + j);
            const float Bkj_real = b_kj_ptr[0];
            const float Bkj_imag = b_kj_ptr[1];
            float *c_kj_ptr = (float *)C + 2 * (k * ldc + j);
            c_kj_ptr[0] += Aik_real * temp1_real + Aik_imag * temp1_imag;
            c_kj_ptr[1] += Aik_real * temp1_imag - Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        float *c_ij_ptr = (float *)C + 2 * (i * ldc + j);
        c_ij_ptr[0] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        c_ij_ptr[1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
