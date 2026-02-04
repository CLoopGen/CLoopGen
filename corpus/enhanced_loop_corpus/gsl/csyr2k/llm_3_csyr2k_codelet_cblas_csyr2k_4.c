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
        float temp_real = 0.0f, temp_imag = 0.0f;
        const float* ptrA_i = (const float*)A + 2 * i * lda;
        const float* ptrB_i = (const float*)B + 2 * i * ldb;
        const float* ptrA_j = (const float*)A + 2 * j * lda;
        const float* ptrB_j = (const float*)B + 2 * j * ldb;
        for (k = 0; k < K; k++) {
            const float Aik_real = ptrA_i[2 * k];
            const float Aik_imag = ptrA_i[2 * k + 1];
            const float Bik_real = ptrB_i[2 * k];
            const float Bik_imag = ptrB_i[2 * k + 1];
            const float Ajk_real = ptrA_j[2 * k];
            const float Ajk_imag = ptrA_j[2 * k + 1];
            const float Bjk_real = ptrB_j[2 * k];
            const float Bjk_imag = ptrB_j[2 * k + 1];
            temp_real += (Aik_real * Bjk_real - Aik_imag * Bjk_imag) +
                         (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
            temp_imag += (Aik_real * Bjk_imag + Aik_imag * Bjk_real) +
                         (Bik_real * Ajk_imag + Bik_imag * Ajk_real);
        }
        ((float*)C)[2 * (i * ldc + j)] += alpha_real * temp_real - alpha_imag * temp_imag;
        ((float*)C)[2 * (i * ldc + j) + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
