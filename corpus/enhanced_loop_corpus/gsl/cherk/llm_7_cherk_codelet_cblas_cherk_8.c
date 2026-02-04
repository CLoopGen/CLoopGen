#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp_real[64];
    float temp_imag[64];
    for (j = 0; j <= i && j < 64; j++) {
        temp_real[j] = 0.;
        temp_imag[j] = 0.;
    }
    for (k = 0; k < K; k++) {
        for (j = 0; j <= i && j < 64; j++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = -(((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real[j] += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag[j] += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
    }
    for (j = 0; j <= i && j < 64; j++) {
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real[j];
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag[j];
    }
}
}
