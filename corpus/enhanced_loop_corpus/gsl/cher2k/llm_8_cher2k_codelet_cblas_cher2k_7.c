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
for (i = 0; i < N; i += 2) {
    for (j = 0; j < i; j++) {
        float temp_real_0 = 0., temp_imag_0 = 0.;
        float temp_real_1 = 0., temp_imag_1 = 0.;
        for (k = 0; k < K; k++) {
            const float Aik0_real = (((const float *)A)[2 * ((i+0) * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * ((i+0) * lda + k) + 1]);
            const float temp1_0_real = alpha_real * Aik0_real - alpha_imag * Aik0_imag;
            const float temp1_0_imag = alpha_real * Aik0_imag + alpha_imag * Aik0_real;
            const float Bik0_real = (((const float *)B)[2 * ((i+0) * ldb + k)]);
            const float Bik0_imag = (((const float *)B)[2 * ((i+0) * ldb + k) + 1]);

            const float Aik1_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
            const float Aik1_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
            const float temp1_1_real = alpha_real * Aik1_real - alpha_imag * Aik1_imag;
            const float temp1_1_imag = alpha_real * Aik1_imag + alpha_imag * Aik1_real;
            const float Bik1_real = (((const float *)B)[2 * ((i+1) * ldb + k)]);
            const float Bik1_imag = (((const float *)B)[2 * ((i+1) * ldb + k) + 1]);

            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            temp_real_0 += ((temp1_0_real * Bjk_real + temp1_0_imag * Bjk_imag) + (Bik0_real * temp2_real + Bik0_imag * temp2_imag));
            temp_imag_0 += ((temp1_0_real * (-Bjk_imag) + temp1_0_imag * Bjk_real) + (Bik0_real * (-temp2_imag) + Bik0_imag * temp2_real));

            temp_real_1 += ((temp1_1_real * Bjk_real + temp1_1_imag * Bjk_imag) + (Bik1_real * temp2_real + Bik1_imag * temp2_imag));
            temp_imag_1 += ((temp1_1_real * (-Bjk_imag) + temp1_1_imag * Bjk_real) + (Bik1_real * (-temp2_imag) + Bik1_imag * temp2_real));
        }
        if (i < N) {
            (((float *)C)[2 * (i * ldc + j)]) += temp_real_0;
            (((float *)C)[2 * (i * ldc + j) + 1]) += temp_imag_0;
        }
        if (i+1 < N) {
            (((float *)C)[2 * ((i+1) * ldc + j)]) += temp_real_1;
            (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += temp_imag_1;
        }
    }
    if (i < N) {
        float temp_real = 0.;
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((float *)C)[2 * (i * ldc + i)]) += 2 * temp_real;
        (((float *)C)[2 * (i * ldc + i) + 1]) = 0.;
    }
    if (i+1 < N) {
        float temp_real = 0.;
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = (((const float *)B)[2 * ((i+1) * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * ((i+1) * ldb + k) + 1]);
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((float *)C)[2 * ((i+1) * ldc + (i+1))]) += 2 * temp_real;
        (((float *)C)[2 * ((i+1) * ldc + (i+1)) + 1]) = 0.;
    }
}
}
