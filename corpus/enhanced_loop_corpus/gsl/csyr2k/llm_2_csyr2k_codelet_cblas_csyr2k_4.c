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
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (k = 0; k < K; k++) {
        float Aik_real, Aik_imag, Bik_real, Bik_imag;
        Aik_real = ((const float*)A)[2 * (i * lda + k)];
        Aik_imag = ((const float*)A)[2 * (i * lda + k) + 1];
        Bik_real = ((const float*)B)[2 * (i * ldb + k)];
        Bik_imag = ((const float*)B)[2 * (i * ldb + k) + 1];
        for (j = i; j < N; j++) {
            const float Ajk_real = ((const float*)A)[2 * (j * lda + k)];
            const float Ajk_imag = ((const float*)A)[2 * (j * lda + k) + 1];
            const float Bjk_real = ((const float*)B)[2 * (j * ldb + k)];
            const float Bjk_imag = ((const float*)B)[2 * (j * ldb + k) + 1];
            float temp_real = Aik_real * Bjk_real - Aik_imag * Bjk_imag +
                              Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            float temp_imag = Aik_real * Bjk_imag + Aik_imag * Bjk_real +
                              Bik_real * Ajk_imag + Bik_imag * Ajk_real;
            ((float*)C)[2 * (i * ldc + j)] += alpha_real * temp_real - alpha_imag * temp_imag;
            ((float*)C)[2 * (i * ldc + j) + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
        }
    }
}
}
