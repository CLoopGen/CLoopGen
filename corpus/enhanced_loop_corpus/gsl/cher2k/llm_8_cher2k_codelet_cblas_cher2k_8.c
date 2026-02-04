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
    for (i = 0; i < N; i += 2) {
        float Aki_real_0 = (((const float *)A)[2 * (k * lda + i)]);
        float Aki_imag_0 = (((const float *)A)[2 * (k * lda + i) + 1]);
        float Bki_real_0 = (((const float *)B)[2 * (k * ldb + i)]);
        float Bki_imag_0 = (((const float *)B)[2 * (k * ldb + i) + 1]);
        float temp1_real_0 = alpha_real * Aki_real_0 - alpha_imag * (-Aki_imag_0);
        float temp1_imag_0 = alpha_real * (-Aki_imag_0) + alpha_imag * Aki_real_0;
        float temp2_real_0 = alpha_real * Bki_real_0 - alpha_imag * Bki_imag_0;
        float temp2_imag_0 = -(alpha_real * Bki_imag_0 + alpha_imag * Bki_real_0);

        float Aki_real_1 = (((const float *)A)[2 * (k * lda + i + 1)]);
        float Aki_imag_1 = (((const float *)A)[2 * (k * lda + i + 1) + 1]);
        float Bki_real_1 = (((const float *)B)[2 * (k * ldb + i + 1)]);
        float Bki_imag_1 = (((const float *)B)[2 * (k * ldb + i + 1) + 1]);
        float temp1_real_1 = alpha_real * Aki_real_1 - alpha_imag * (-Aki_imag_1);
        float temp1_imag_1 = alpha_real * (-Aki_imag_1) + alpha_imag * Aki_real_1;
        float temp2_real_1 = alpha_real * Bki_real_1 - alpha_imag * Bki_imag_1;
        float temp2_imag_1 = -(alpha_real * Bki_imag_1 + alpha_imag * Bki_real_1);

        for (j = 0; j < i; j++) {
            float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);

            float term1_real = temp1_real_0 * Bkj_real - temp1_imag_0 * Bkj_imag;
            float term1_imag = temp1_real_0 * Bkj_imag + temp1_imag_0 * Bkj_real;
            float term2_real = temp2_real_0 * Akj_real - temp2_imag_0 * Akj_imag;
            float term2_imag = temp2_real_0 * Akj_imag + temp2_imag_0 * Akj_real;

            (((float *)C)[2 * (i * lda + j)]) += term1_real + term2_real;
            (((float *)C)[2 * (i * lda + j) + 1]) += term1_imag + term2_imag;

            if (i + 1 < N) {
                term1_real = temp1_real_1 * Bkj_real - temp1_imag_1 * Bkj_imag;
                term1_imag = temp1_real_1 * Bkj_imag + temp1_imag_1 * Bkj_real;
                term2_real = temp2_real_1 * Akj_real - temp2_imag_1 * Akj_imag;
                term2_imag = temp2_real_1 * Akj_imag + temp2_imag_1 * Akj_real;

                (((float *)C)[2 * ((i+1) * lda + j)]) += term1_real + term2_real;
                (((float *)C)[2 * ((i+1) * lda + j) + 1]) += term1_imag + term2_imag;
            }
        }
        if (i < N) {
            (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real_0 * Bki_real_0 - temp1_imag_0 * Bki_imag_0);
            (((float *)C)[2 * (i * lda + i) + 1]) = 0.;
        }
        if (i + 1 < N) {
            (((float *)C)[2 * ((i+1) * lda + (i+1))]) += 2 * (temp1_real_1 * Bki_real_1 - temp1_imag_1 * Bki_imag_1);
            (((float *)C)[2 * ((i+1) * lda + (i+1)) + 1]) = 0.;
        }
    }
}
}
