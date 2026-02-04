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
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (k = 0; k < K; k++) {
        float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
        float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
        float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
        float temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        float temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
        for (j = i; j < N; j++) {
            float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);
            float product1_real = temp1_real * Bkj_real - temp1_imag * Bkj_imag;
            float product1_imag = temp1_real * Bkj_imag + temp1_imag * Bkj_real;
            float product2_real = temp2_real * Akj_real - temp2_imag * Akj_imag;
            float product2_imag = temp2_real * Akj_imag + temp2_imag * Akj_real;
            float sum_real = product1_real + product2_real;
            float sum_imag = product1_imag + product2_imag;
            float c_real = (((float *)C)[2 * (i * lda + j)]);
            float c_imag = (((float *)C)[2 * (i * lda + j) + 1]);
            c_real += sum_real;
            c_imag += sum_imag;
            (((float *)C)[2 * (i * lda + j)]) = c_real;
            (((float *)C)[2 * (i * lda + j) + 1]) = c_imag;
        }
    }
}
}
