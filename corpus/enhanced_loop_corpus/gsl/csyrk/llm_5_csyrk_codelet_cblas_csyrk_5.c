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
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            if (k % 2 == 0) {
                const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
                const float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
                const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
                const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
                temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
                temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
            } else {
                const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
                const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
                temp_real += Aki_real * Akj_real;
            }
        }
        float C_val_real = (((float *)C)[2 * (i * ldc + j)]);
        float C_val_imag = (((float *)C)[2 * (i * ldc + j) + 1]);
        (((float *)C)[2 * (i * ldc + j)]) = C_val_real + alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) = C_val_imag + alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
