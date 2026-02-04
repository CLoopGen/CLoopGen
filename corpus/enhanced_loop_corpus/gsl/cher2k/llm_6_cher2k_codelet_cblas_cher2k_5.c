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
    float temp_real_diag = 0.;
    for (k = 0; k < K; k++) {
        const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
        const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
        const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
        const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
        const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
        temp_real_diag += temp1_real * Bik_real + temp1_imag * Bik_imag;
    }
    (((float *)C)[2 * (i * ldc + i)]) += 2 * temp_real_diag;
    (((float *)C)[2 * (i * ldc + i) + 1]) = 0.;

    for (j = i + 1; j < N; j++) {
        float sum_real_upper = 0.;
        float sum_imag_upper = 0.;
        float sum_real_lower = 0.;
        float sum_imag_lower = 0.;
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);

            const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

            sum_real_upper += temp1_real * Bjk_real + temp1_imag * Bjk_imag;
            sum_imag_upper += temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real;

            sum_real_lower += Bik_real * temp2_real + Bik_imag * temp2_imag;
            sum_imag_lower += Bik_real * (-temp2_imag) + Bik_imag * temp2_real;
        }
        const float total_real = sum_real_upper + sum_real_lower;
        const float total_imag = sum_imag_upper + sum_imag_lower;

        (((float *)C)[2 * (i * ldc + j)]) += total_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += total_imag;
    }
}
}
