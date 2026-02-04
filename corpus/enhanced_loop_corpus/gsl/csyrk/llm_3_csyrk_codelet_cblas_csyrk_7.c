#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const float *A_row_k = &(((const float *)A)[2 * k * lda]);
            const float Aki_real = A_row_k[2 * i];
            const float Aki_imag = A_row_k[2 * i + 1];
            const float Akj_real = A_row_k[2 * j];
            const float Akj_imag = A_row_k[2 * j + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        float *C_row_i = &(((float *)C)[2 * i * ldc]);
        C_row_i[2 * j] += alpha_real * temp_real - alpha_imag * temp_imag;
        C_row_i[2 * j + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
