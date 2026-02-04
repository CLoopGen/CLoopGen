#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const ptrdiff_t A_offset_i = i * lda;
    const ptrdiff_t B_offset_i = i * ldb;
    const ptrdiff_t C_offset_i = i * ldc;
    for (j = 0; j < i; j++) {
        const ptrdiff_t A_offset_j = j * lda;
        const ptrdiff_t B_offset_j = j * ldb;
        const ptrdiff_t C_offset_ij = C_offset_i + j;
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const ptrdiff_t idxA_ik = 2 * (A_offset_i + k);
            const ptrdiff_t idxB_ik = 2 * (B_offset_i + k);
            const ptrdiff_t idxA_jk = 2 * (A_offset_j + k);
            const ptrdiff_t idxB_jk = 2 * (B_offset_j + k);
            const float Aik_real = ((const float *)A)[idxA_ik];
            const float Aik_imag = ((const float *)A)[idxA_ik + 1];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = ((const float *)B)[idxB_ik];
            const float Bik_imag = ((const float *)B)[idxB_ik + 1];
            const float Ajk_real = ((const float *)A)[idxA_jk];
            const float Ajk_imag = ((const float *)A)[idxA_jk + 1];
            const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const float Bjk_real = ((const float *)B)[idxB_jk];
            const float Bjk_imag = ((const float *)B)[idxB_jk + 1];
            temp_real += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));
        }
        const ptrdiff_t idxC_ij = 2 * C_offset_ij;
        ((float *)C)[idxC_ij] += temp_real;
        ((float *)C)[idxC_ij + 1] += temp_imag;
    }
    {
        float temp_real = 0.;
        for (k = 0; k < K; k++) {
            const ptrdiff_t idxA_ik = 2 * (A_offset_i + k);
            const ptrdiff_t idxB_ik = 2 * (B_offset_i + k);
            const float Aik_real = ((const float *)A)[idxA_ik];
            const float Aik_imag = ((const float *)A)[idxA_ik + 1];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = ((const float *)B)[idxB_ik];
            const float Bik_imag = ((const float *)B)[idxB_ik + 1];
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        const ptrdiff_t idxC_ii = 2 * (C_offset_i + i);
        ((float *)C)[idxC_ii] += 2 * temp_real;
        ((float *)C)[idxC_ii + 1] = 0.;
    }
}
}
