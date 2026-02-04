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
    const float* A_row = &(((const float*)A)[2 * k * lda]);
    const float* B_row = &(((const float*)B)[2 * k * ldb]);
    for (i = 0; i < N; i++) {
        float Aki_real = A_row[2 * i];
        float Aki_imag = A_row[2 * i + 1];
        float Bki_real = B_row[2 * i];
        float Bki_imag = B_row[2 * i + 1];
        float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
        float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);
        {
            (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            (((float *)C)[2 * (i * lda + i) + 1]) = 0.;
        }
        float* C_irow = &(((float*)C)[2 * i * lda]);
        for (j = i + 1; j < N; j++) {
            float Akj_real = A_row[2 * j];
            float Akj_imag = A_row[2 * j + 1];
            float Bkj_real = B_row[2 * j];
            float Bkj_imag = B_row[2 * j + 1];
            C_irow[2 * j] += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
            C_irow[2 * j + 1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
        }
    }
}
}
