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
for (k = 0; k < K; k += 2) {
    for (i = 0; i < N; i++) {
        float Aki_real, Aki_imag, Bki_real, Bki_imag;
        float temp1_real, temp1_imag, temp2_real, temp2_imag;

        if (k < K) {
            Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
            Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
            temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);
        } else {
            temp1_real = temp1_imag = temp2_real = temp2_imag = 0.0f;
        }

        float Aki_real_next = 0.0f, Aki_imag_next = 0.0f;
        float Bki_real_next = 0.0f, Bki_imag_next = 0.0f;
        float temp1_real_next = 0.0f, temp1_imag_next = 0.0f;
        float temp2_real_next = 0.0f, temp2_imag_next = 0.0f;

        if (k + 1 < K) {
            Aki_real_next = (((const float *)A)[2 * ((k+1) * lda + i)]);
            Aki_imag_next = (((const float *)A)[2 * ((k+1) * lda + i) + 1]);
            Bki_real_next = (((const float *)B)[2 * ((k+1) * ldb + i)]);
            Bki_imag_next = (((const float *)B)[2 * ((k+1) * ldb + i) + 1]);
            temp1_real_next = alpha_real * Aki_real_next - alpha_imag * (-Aki_imag_next);
            temp1_imag_next = alpha_real * (-Aki_imag_next) + alpha_imag * Aki_real_next;
            temp2_real_next = alpha_real * Bki_real_next - alpha_imag * Bki_imag_next;
            temp2_imag_next = -(alpha_real * Bki_imag_next + alpha_imag * Bki_real_next);
        }

        for (j = 0; j < i; j++) {
            float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);

            float term1_real = temp1_real * Bkj_real - temp1_imag * Bkj_imag;
            float term1_imag = temp1_real * Bkj_imag + temp1_imag * Bkj_real;
            float term2_real = temp2_real * Akj_real - temp2_imag * Akj_imag;
            float term2_imag = temp2_real * Akj_imag + temp2_imag * Akj_real;

            (((float *)C)[2 * (i * lda + j)]) += term1_real + term2_real;
            (((float *)C)[2 * (i * lda + j) + 1]) += term1_imag + term2_imag;

            if (k + 1 < K) {
                float Akj_real_next = (((const float *)A)[2 * ((k+1) * lda + j)]);
                float Akj_imag_next = (((const float *)A)[2 * ((k+1) * lda + j) + 1]);
                float Bkj_real_next = (((const float *)B)[2 * ((k+1) * ldb + j)]);
                float Bkj_imag_next = (((const float *)B)[2 * ((k+1) * ldb + j) + 1]);

                term1_real = temp1_real_next * Bkj_real_next - temp1_imag_next * Bkj_imag_next;
                term1_imag = temp1_real_next * Bkj_imag_next + temp1_imag_next * Bkj_real_next;
                term2_real = temp2_real_next * Akj_real_next - temp2_imag_next * Akj_imag_next;
                term2_imag = temp2_real_next * Akj_imag_next + temp2_imag_next * Akj_real_next;

                (((float *)C)[2 * (i * lda + j)]) += term1_real + term2_real;
                (((float *)C)[2 * (i * lda + j) + 1]) += term1_imag + term2_imag;
            }
        }
        (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
        (((float *)C)[2 * (i * lda + i) + 1]) = 0.;

        if (k + 1 < K) {
            (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real_next * Bki_real_next - temp1_imag_next * Bki_imag_next);
        }
    }
}
}
