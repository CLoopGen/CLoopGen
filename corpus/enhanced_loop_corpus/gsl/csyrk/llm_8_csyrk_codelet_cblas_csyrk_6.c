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
    for (j = 0; j <= i; j += 2) { // Increased loop stride to reduce trip count and increase computational intensity per iteration
        float temp_real0 = 0., temp_imag0 = 0.;
        float temp_real1 = 0., temp_imag1 = 0.;
        for (k = 0; k < K; k++) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real0 += Aik0_real * Ajk0_real - Aik0_imag * Ajk0_imag;
            temp_imag0 += Aik0_real * Ajk0_imag + Aik0_imag * Ajk0_real;

            if (j + 1 <= i) { // Unroll j-loop with partial guard
                const float Ajk1_real = (((const float *)A)[2 * ((j+1) * lda + k)]);
                const float Ajk1_imag = (((const float *)A)[2 * ((j+1) * lda + k) + 1]);
                temp_real1 += Aik0_real * Ajk1_real - Aik0_imag * Ajk1_imag;
                temp_imag1 += Aik0_real * Ajk1_imag + Aik0_imag * Ajk1_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real0 - alpha_imag * temp_imag0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag0 + alpha_imag * temp_real0;
        if (j + 1 <= i) {
            (((float *)C)[2 * (i * ldc + j + 1)]) += alpha_real * temp_real1 - alpha_imag * temp_imag1;
            (((float *)C)[2 * (i * ldc + j + 1) + 1]) += alpha_real * temp_imag1 + alpha_imag * temp_real1;
        }
    }
}
}
