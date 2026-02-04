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
    float temp_real_inner;
    float temp_imag_inner;
    for (j = i; j < N; j++) {
        temp_real_inner = 0.;
        temp_imag_inner = 0.;
        k = 0;
        for (; k < K; k += 2) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real_inner += Aik0_real * Ajk0_real - Aik0_imag * Ajk0_imag;
            temp_imag_inner += Aik0_real * Ajk0_imag + Aik0_imag * Ajk0_real;

            if (k + 1 < K) {
                const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
                const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
                const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
                const float Ajk1_imag = (((const float *)A)[2 * (j * lda + k + 1) + 1]);
                temp_real_inner += Aik1_real * Ajk1_real - Aik1_imag * Ajk1_imag;
                temp_imag_inner += Aik1_real * Ajk1_imag + Aik1_imag * Ajk1_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real_inner - alpha_imag * temp_imag_inner;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag_inner + alpha_imag * temp_real_inner;
    }
}
}
