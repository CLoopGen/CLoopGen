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
        const float *Bj_base = (const float *)B + 2 * ldb * i + 2 * j;
        const float Bij_real = Bj_base[0];
        const float Bij_imag = Bj_base[1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        {
            const float *A_row = (const float *)A + 2 * (i * lda + i);
            const float Aii_real = A_row[0];
            const float Aii_imag = A_row[1];
            float *Cij = (float *)C + 2 * (i * ldc + j);
            Cij[0] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            Cij[1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        for (k = i + 1; k < n1; k++) {
            const float *Aik_ptr = (const float *)A + 2 * (i * lda + k);
            const float Aik_real = Aik_ptr[0];
            const float Aik_imag = Aik_ptr[1];
            const float *Bkj_ptr = (const float *)B + 2 * (ldb * k + j);
            const float Bkj_real = Bkj_ptr[0];
            const float Bkj_imag = Bkj_ptr[1];
            float *Ckj = (float *)C + 2 * (k * ldc + j);
            Ckj[0] += Aik_real * temp1_real - Aik_imag * temp1_imag;
            Ckj[1] += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        float *Cij_final = (float *)C + 2 * (i * ldc + j);
        Cij_final[0] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        Cij_final[1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
