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
    for (j = 0; j < i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float *A_row_i = &((const float *)A)[2 * (i * lda)];
        const float *B_row_i = &((const float *)B)[2 * (i * ldb)];
        const float *A_row_j = &((const float *)A)[2 * (j * lda)];
        const float *B_row_j = &((const float *)B)[2 * (j * ldb)];
        for (k = 0; k < K; k++) {
            const float Aik_real = A_row_i[2 * k];
            const float Aik_imag = A_row_i[2 * k + 1];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = B_row_i[2 * k];
            const float Bik_imag = B_row_i[2 * k + 1];
            const float Ajk_real = A_row_j[2 * k];
            const float Ajk_imag = A_row_j[2 * k + 1];
            const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const float Bjk_real = B_row_j[2 * k];
            const float Bjk_imag = B_row_j[2 * k + 1];
            temp_real += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));
        }
        float *Cij = &((float *)C)[2 * (i * ldc + j)];
        Cij[0] += temp_real;
        Cij[1] += temp_imag;
    }
    {
        float temp_real = 0.;
        const float *A_row_i = &((const float *)A)[2 * (i * lda)];
        const float *B_row_i = &((const float *)B)[2 * (i * ldb)];
        for (k = 0; k < K; k++) {
            const float Aik_real = A_row_i[2 * k];
            const float Aik_imag = A_row_i[2 * k + 1];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = B_row_i[2 * k];
            const float Bik_imag = B_row_i[2 * k + 1];
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        float *Cii = &((float *)C)[2 * (i * ldc + i)];
        Cii[0] += 2 * temp_real;
        Cii[1] = 0.;
    }
}
}
