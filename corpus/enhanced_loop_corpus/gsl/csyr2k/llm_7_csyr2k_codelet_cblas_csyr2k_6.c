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
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp_real_i[K];
    float temp_imag_i[K];
    for (k = 0; k < K; k++) {
        const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
        const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
        const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
        temp_real_i[k] = Aik_real + Bik_real;
        temp_imag_i[k] = Aik_imag + Bik_imag;
    }
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            const float term1_real = temp_real_i[k] * Bjk_real - temp_imag_i[k] * Bjk_imag;
            const float term1_imag = temp_real_i[k] * Bjk_imag + temp_imag_i[k] * Bjk_real;

            const float term2_real = (((const float *)B)[2 * (i * ldb + k)]) * Ajk_real - (((const float *)B)[2 * (i * ldb + k) + 1]) * Ajk_imag;
            const float term2_imag = (((const float *)B)[2 * (i * ldb + k)]) * Ajk_imag + (((const float *)B)[2 * (i * ldb + k) + 1]) * Ajk_real;

            temp_real += term1_real + term2_real;
            temp_imag += term1_imag + term2_imag;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
