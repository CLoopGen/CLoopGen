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
    for (i = 0; i < n1; i++) {
        const int bij_offset = 2 * (ldb * i + j);
        const float Bij_real = ((const float*)B)[bij_offset];
        const float Bij_imag = ((const float*)B)[bij_offset + 1];
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.0f;
        float temp2_imag = 0.0f;
        for (k = 0; k < i; k++) {
            const int aik_offset = 2 * (i * lda + k);
            const float Aik_real = ((const float*)A)[aik_offset];
            const float Aik_imag = ((const float*)A)[aik_offset + 1];
            const int bkj_offset = 2 * (ldb * k + j);
            const float Bkj_real = ((const float*)B)[bkj_offset];
            const float Bkj_imag = ((const float*)B)[bkj_offset + 1];
            const int ckj_offset = 2 * (k * ldc + j);
            ((float*)C)[ckj_offset] += Aik_real * temp1_real - Aik_imag * temp1_imag;
            ((float*)C)[ckj_offset + 1] += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const int aii_offset = 2 * (i * lda + i);
            const float Aii_real = ((const float*)A)[aii_offset];
            const float Aii_imag = ((const float*)A)[aii_offset + 1];
            const int cij_offset = 2 * (i * ldc + j);
            ((float*)C)[cij_offset] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            ((float*)C)[cij_offset + 1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        const int cij_final = 2 * (i * ldc + j);
        ((float*)C)[cij_final] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((float*)C)[cij_final + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
