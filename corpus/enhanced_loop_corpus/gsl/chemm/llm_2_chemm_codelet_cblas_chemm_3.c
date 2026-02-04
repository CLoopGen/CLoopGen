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
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        for (k = 0; k < i; k++) {
            const int idx_Aik = 2 * (i * lda + k);
            const float Aik_real = (((const float *)A)[idx_Aik]);
            const float Aik_imag = (((const float *)A)[idx_Aik + 1]);
            const int idx_Bkj = 2 * (ldb * k + j);
            const float Bkj_real = (((const float *)B)[idx_Bkj]);
            const float Bkj_imag = (((const float *)B)[idx_Bkj + 1]);
            const int idx_C1 = 2 * (k * ldc + j);
            ((float *)C)[idx_C1] += Aik_real * temp1_real + Aik_imag * temp1_imag;
            ((float *)C)[idx_C1 + 1] += Aik_real * temp1_imag - Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const float Aii_real = (((const float *)A)[2 * (i * lda + i)]);
            const int idx_C2 = 2 * (i * ldc + j);
            ((float *)C)[idx_C2] += temp1_real * Aii_real;
            ((float *)C)[idx_C2 + 1] += temp1_imag * Aii_real;
        }
        const int idx_C3 = 2 * (i * ldc + j);
        ((float *)C)[idx_C3] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float *)C)[idx_C3 + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
