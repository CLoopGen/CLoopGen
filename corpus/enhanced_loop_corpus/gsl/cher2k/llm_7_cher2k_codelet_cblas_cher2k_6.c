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
// Reorder loops to j-i-k and restructure computation to remove loop-carried dependencies
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        float sum_real = 0.0f;
        float sum_imag = 0.0f;
        for (k = 0; k < K; k++) {
            float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
            float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
            float Akj_real = (j == i) ? Aki_real : (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (j == i) ? Aki_imag : (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (j == i) ? Bki_real : (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (j == i) ? Bki_imag : (((const float *)B)[2 * (k * ldb + j) + 1]);

            float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

            float term1_real = temp1_real * Bkj_real - temp1_imag * Bkj_imag;
            float term1_imag = temp1_real * Bkj_imag + temp1_imag * Bkj_real;
            float term2_real = temp2_real * Akj_real - temp2_imag * Akj_imag;
            float term2_imag = temp2_real * Akj_imag + temp2_imag * Akj_real;

            if (j == i) {
                sum_real += 2 * term1_real;
            } else {
                sum_real += term1_real + term2_real;
                sum_imag += term1_imag + term2_imag;
            }
        }
        if (j == i) {
            (((float *)C)[2 * (i * lda + i)]) += sum_real;
            (((float *)C)[2 * (i * lda + i) + 1]) = 0.;
        } else {
            (((float *)C)[2 * (i * lda + j)]) += sum_real;
            (((float *)C)[2 * (i * lda + j) + 1]) += sum_imag;
        }
    }
}
}
