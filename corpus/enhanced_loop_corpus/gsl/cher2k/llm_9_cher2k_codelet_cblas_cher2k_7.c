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
    for (j = 0; j < i; j += 2) {
        float temp_real_0 = 0., temp_imag_0 = 0.;
        float temp_real_1 = 0., temp_imag_1 = 0.;
        int j1 = j + 1;
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;

            const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);

            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float temp2_0_real = alpha_real * Ajk0_real - alpha_imag * Ajk0_imag;
            const float temp2_0_imag = alpha_real * Ajk0_imag + alpha_imag * Ajk0_real;

            const float Bjk0_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk0_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            temp_real_0 += ((temp1_real * Bjk0_real + temp1_imag * Bjk0_imag) + (Bik_real * temp2_0_real + Bik_imag * temp2_0_imag));
            temp_imag_0 += ((temp1_real * (-Bjk0_imag) + temp1_imag * Bjk0_real) + (Bik_real * (-temp2_0_imag) + Bik_imag * temp2_0_real));

            if (j1 < i) {
                const float Ajk1_real = (((const float *)A)[2 * (j1 * lda + k)]);
                const float Ajk1_imag = (((const float *)A)[2 * (j1 * lda + k) + 1]);
                const float temp2_1_real = alpha_real * Ajk1_real - alpha_imag * Ajk1_imag;
                const float temp2_1_imag = alpha_real * Ajk1_imag + alpha_imag * Ajk1_real;

                const float Bjk1_real = (((const float *)B)[2 * (j1 * ldb + k)]);
                const float Bjk1_imag = (((const float *)B)[2 * (j1 * ldb + k) + 1]);

                temp_real_1 += ((temp1_real * Bjk1_real + temp1_imag * Bjk1_imag) + (Bik_real * temp2_1_real + Bik_imag * temp2_1_imag));
                temp_imag_1 += ((temp1_real * (-Bjk1_imag) + temp1_imag * Bjk1_real) + (Bik_real * (-temp2_1_imag) + Bik_imag * temp2_1_real));
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += temp_real_0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp_imag_0;

        if (j1 < i) {
            (((float *)C)[2 * (i * ldc + j1)]) += temp_real_1;
            (((float *)C)[2 * (i * ldc + j1) + 1]) += temp_imag_1;
        }
    }
    {
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
}
}
