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
    for (j = i; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        k = 0;
        // Unroll loop by factor of 2 to reduce trip count and increase arithmetic per iteration
        for (; k < K - 1; k += 2) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bik0_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik0_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bjk0_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk0_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
            const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
            const float Bik1_real = (((const float *)B)[2 * (i * ldb + k + 1)]);
            const float Bik1_imag = (((const float *)B)[2 * (i * ldb + k + 1) + 1]);
            const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
            const float Ajk1_imag = (((const float *)A)[2 * (j * lda + k + 1) + 1]);
            const float Bjk1_real = (((const float *)B)[2 * (j * ldb + k + 1)]);
            const float Bjk1_imag = (((const float *)B)[2 * (j * ldb + k + 1) + 1]);

            temp_real += (Aik0_real * Bjk0_real - Aik0_imag * Bjk0_imag) + (Bik0_real * Ajk0_real - Bik0_imag * Ajk0_imag);
            temp_imag += (Aik0_real * Bjk0_imag + Aik0_imag * Bjk0_real) + (Bik0_real * Ajk0_imag + Bik0_imag * Ajk0_real);

            temp_real += (Aik1_real * Bjk1_real - Aik1_imag * Bjk1_imag) + (Bik1_real * Ajk1_real - Bik1_imag * Ajk1_imag);
            temp_imag += (Aik1_real * Bjk1_imag + Aik1_imag * Bjk1_real) + (Bik1_real * Ajk1_imag + Bik1_imag * Ajk1_real);
        }
        // Handle remaining element if K is odd
        for (; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);
            temp_real += (Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
            temp_imag += (Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real);
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
