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
    {
        float temp_real = 0.;
        for (k = 0; k < K; k++) {
            const int idx_A = 2 * (i * lda + k);
            const int idx_B = 2 * (i * ldb + k);
            const float Aik_real = ((const float *)A)[idx_A];
            const float Aik_imag = ((const float *)A)[idx_A + 1];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = ((const float *)B)[idx_B];
            const float Bik_imag = ((const float *)B)[idx_B + 1];
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        const int idx_C_diag = 2 * (i * ldc + i);
        ((float *)C)[idx_C_diag] += 2 * temp_real;
        ((float *)C)[idx_C_diag + 1] = 0.;
    }
    for (j = i + 1; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const int idx_Ai = 2 * (i * lda + k);
            const int idx_Aj = 2 * (j * lda + k);
            const int idx_Bi = 2 * (i * ldb + k);
            const int idx_Bj = 2 * (j * ldb + k);
            const float Aik_real = ((const float *)A)[idx_Ai];
            const float Aik_imag = ((const float *)A)[idx_Ai + 1];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = ((const float *)B)[idx_Bi];
            const float Bik_imag = ((const float *)B)[idx_Bi + 1];
            const float Ajk_real = ((const float *)A)[idx_Aj];
            const float Ajk_imag = ((const float *)A)[idx_Aj + 1];
            const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const float Bjk_real = ((const float *)B)[idx_Bj];
            const float Bjk_imag = ((const float *)B)[idx_Bj + 1];
            temp_real += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));
        }
        const int idx_C = 2 * (i * ldc + j);
        ((float *)C)[idx_C] += temp_real;
        ((float *)C)[idx_C + 1] += temp_imag;
    }
}
}
