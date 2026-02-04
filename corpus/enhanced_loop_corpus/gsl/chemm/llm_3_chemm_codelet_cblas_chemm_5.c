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
for (j = 0; j < n2; j++) {
    const float *A_j = (const float *)A + 2 * lda * j;
    const float Ajj_real = A_j[2 * j];
    for (i = 0; i < n1; i++) {
        const float *B_i = (const float *)B + 2 * ldb * i;
        const float Bij_real = B_i[2 * j];
        const float Bij_imag = B_i[2 * j + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        for (k = 0; k < j; k++) {
            const float Ajk_real = A_j[2 * k];
            const float Ajk_imag = A_j[2 * k + 1];
            const float Bik_real = B_i[2 * k];
            const float Bik_imag = B_i[2 * k + 1];
            float *C_ik = (float *)C + 2 * (i * ldc + k);
            C_ik[0] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            C_ik[1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real + Bik_imag * Ajk_imag;
            temp2_imag += -Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        float *C_ij = (float *)C + 2 * (i * ldc + j);
        C_ij[0] += temp1_real * Ajj_real;
        C_ij[1] += temp1_imag * Ajj_real;
        C_ij[0] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        C_ij[1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
