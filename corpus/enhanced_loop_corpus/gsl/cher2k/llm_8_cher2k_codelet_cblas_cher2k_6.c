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
        if (i + 1 < N) {
            float Aki0_real = (((const float *)A)[2 * (k * lda + i)]);
            float Aki0_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            float Bki0_real = (((const float *)B)[2 * (k * ldb + i)]);
            float Bki0_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
            float temp1_0_real = alpha_real * Aki0_real - alpha_imag * (-Aki0_imag);
            float temp1_0_imag = alpha_real * (-Aki0_imag) + alpha_imag * Aki0_real;
            float temp2_0_real = alpha_real * Bki0_real - alpha_imag * Bki0_imag;
            float temp2_0_imag = -(alpha_real * Bki0_imag + alpha_imag * Bki0_real);

            float Aki1_real = (((const float *)A)[2 * (k * lda + i + 1)]);
            float Aki1_imag = (((const float *)A)[2 * (k * lda + i + 1) + 1]);
            float Bki1_real = (((const float *)B)[2 * (k * ldb + i + 1)]);
            float Bki1_imag = (((const float *)B)[2 * (k * ldb + i + 1) + 1]);
            float temp1_1_real = alpha_real * Aki1_real - alpha_imag * (-Aki1_imag);
            float temp1_1_imag = alpha_real * (-Aki1_imag) + alpha_imag * Aki1_real;
            float temp2_1_real = alpha_real * Bki1_real - alpha_imag * Bki1_imag;
            float temp2_1_imag = -(alpha_real * Bki1_imag + alpha_imag * Bki1_real);

            (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_0_real * Bki0_real - temp1_0_imag * Bki0_imag);
            (((float *)C)[2 * (i * lda + i) + 1]) = 0.;

            (((float *)C)[2 * ((i+1) * lda + (i+1))]) += 2 * (temp1_1_real * Bki1_real - temp1_1_imag * Bki1_imag);
            (((float *)C)[2 * ((i+1) * lda + (i+1)) + 1]) = 0.;

            for (j = i + 1; j < N; j++) {
                float Akj0_real = (((const float *)A)[2 * (k * lda + j)]);
                float Akj0_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
                float Bkj0_real = (((const float *)B)[2 * (k * ldb + j)]);
                float Bkj0_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);

                float term0_real = temp1_0_real * Bkj0_real - temp1_0_imag * Bkj0_imag;
                float term0_imag = temp1_0_real * Bkj0_imag + temp1_0_imag * Bkj0_real;
                float term2_0_real = temp2_0_real * Akj0_real - temp2_0_imag * Akj0_imag;
                float term2_0_imag = temp2_0_real * Akj0_imag + temp2_0_imag * Akj0_real;

                (((float *)C)[2 * (i * lda + j)]) += term0_real + term2_0_real;
                (((float *)C)[2 * (i * lda + j) + 1]) += term0_imag + term2_0_imag;

                if (j > i + 1) {
                    float Akj1_real = Akj0_real;
                    float Akj1_imag = Akj0_imag;
                    float Bkj1_real = Bkj0_real;
                    float Bkj1_imag = Bkj0_imag;

                    float term1_real = temp1_1_real * Bkj1_real - temp1_1_imag * Bkj1_imag;
                    float term1_imag = temp1_1_real * Bkj1_imag + temp1_1_imag * Bkj1_real;
                    float term2_1_real = temp2_1_real * Akj1_real - temp2_1_imag * Akj1_imag;
                    float term2_1_imag = temp2_1_real * Akj1_imag + temp2_1_imag * Akj1_real;

                    (((float *)C)[2 * ((i+1) * lda + j)]) += term1_real + term2_1_real;
                    (((float *)C)[2 * ((i+1) * lda + j) + 1]) += term1_imag + term2_1_imag;
                }
            }
        } else {
            float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
            float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
            float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);
            {
                (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
                (((float *)C)[2 * (i * lda + i) + 1]) = 0.;
            }
            for (j = i + 1; j < N; j++) {
                float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
                float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
                float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
                float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);
                (((float *)C)[2 * (i * lda + j)]) += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
                (((float *)C)[2 * (i * lda + j) + 1]) += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
        }
    }
}
}
