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
    float temp_real[64]; // Local accumulation array to break WAW dependencies
    float temp_imag[64];
    for (j = i; j < N && j < i + 64; j++) {
        temp_real[j - i] = 0.;
        temp_imag[j - i] = 0.;
    }
    for (k = 0; k < K; k++) {
        for (j = i; j < N && j < i + 64; j++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = -(((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real[j - i] += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag[j - i] += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
    }
    for (j = i; j < N && j < i + 64; j++) {
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real[j - i];
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag[j - i];
    }
    // Handle remaining j values beyond the block size of 64
    for (; j < N; j++) {
        float final_real = 0., final_imag = 0.;
        for (k = 0; k < K; k++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = -(((const float *)A)[2 * (k * lda + i) + 1]);
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            final_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            final_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * final_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * final_imag;
    }
}
}
