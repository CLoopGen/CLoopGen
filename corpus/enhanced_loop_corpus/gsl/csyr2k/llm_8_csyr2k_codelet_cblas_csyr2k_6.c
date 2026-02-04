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
for (i = 0; i < N; i += 2) {
    for (j = 0; j <= i; j++) {
        float temp_real1 = 0., temp_imag1 = 0.;
        float temp_real2 = 0., temp_imag2 = 0.;
        for (k = 0; k < K; k++) {
            const float Aik1_real = (((const float *)A)[2 * ((i+0) * lda + k)]);
            const float Aik1_imag = (((const float *)A)[2 * ((i+0) * lda + k) + 1]);
            const float Bik1_real = (((const float *)B)[2 * ((i+0) * ldb + k)]);
            const float Bik1_imag = (((const float *)B)[2 * ((i+0) * ldb + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            const float Aik2_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
            const float Aik2_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
            const float Bik2_real = (((const float *)B)[2 * ((i+1) * ldb + k)]);
            const float Bik2_imag = (((const float *)B)[2 * ((i+1) * ldb + k) + 1]);

            temp_real1 += (Aik1_real * Bjk_real - Aik1_imag * Bjk_imag) + (Bik1_real * Ajk_real - Bik1_imag * Ajk_imag);
            temp_imag1 += (Aik1_real * Bjk_imag + Aik1_imag * Bjk_real) + (Bik1_real * Ajk_imag + Bik1_imag * Ajk_real);

            temp_real2 += (Aik2_real * Bjk_real - Aik2_imag * Bjk_imag) + (Bik2_real * Ajk_real - Bik2_imag * Ajk_imag);
            temp_imag2 += (Aik2_real * Bjk_imag + Aik2_imag * Bjk_real) + (Bik2_real * Ajk_imag + Bik2_imag * Ajk_real);
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real1 - alpha_imag * temp_imag1;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag1 + alpha_imag * temp_real1;
        if (i + 1 < N) {
            (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp_real2 - alpha_imag * temp_imag2;
            (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp_imag2 + alpha_imag * temp_real2;
        }
    }
}
}
