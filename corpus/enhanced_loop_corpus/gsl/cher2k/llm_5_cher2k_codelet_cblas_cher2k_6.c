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
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
        float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
        float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);

        // Reorganize control flow: early exit based on magnitude
        float norm_Aki = Aki_real * Aki_real + Aki_imag * Aki_imag;
        if (norm_Aki < 1e-8f) continue;

        float norm_Bki = Bki_real * Bki_real + Bki_imag * Bki_imag;
        if (norm_Bki < 1e-8f) continue;

        float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
        float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

        // Always update diagonal
        (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
        (((float *)C)[2 * (i * lda + i) + 1]) = 0.;

        // Skip off-diagonal updates if both vectors are too small
        if (norm_Aki * norm_Bki < 1e-12f) continue;

        for (j = i + 1; j < N; j++) {
            float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);

            float cross1_real = temp1_real * Bkj_real - temp1_imag * Bkj_imag;
            float cross1_imag = temp1_real * Bkj_imag + temp1_imag * Bkj_real;
            float cross2_real = temp2_real * Akj_real - temp2_imag * Akj_imag;
            float cross2_imag = temp2_real * Akj_imag + temp2_imag * Akj_real;

            (((float *)C)[2 * (i * lda + j)]) += cross1_real + cross2_real;
            (((float *)C)[2 * (i * lda + j) + 1]) += cross1_imag + cross2_imag;
        }
    }
}
}
