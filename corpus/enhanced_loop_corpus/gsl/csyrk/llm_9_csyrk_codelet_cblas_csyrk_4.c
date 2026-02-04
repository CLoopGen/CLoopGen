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
    for (j = i; j < N; j += 2) {
        float temp_real_0 = 0., temp_real_1 = 0.;
        float temp_imag_0 = 0., temp_imag_1 = 0.;
        int j1 = j + 1;

        for (k = 0; k < K; ++k) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);

            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real_0 += Aik_real * Ajk0_real - Aik_imag * Ajk0_imag;
            temp_imag_0 += Aik_real * Ajk0_imag + Aik_imag * Ajk0_real;

            if (j1 < N) {
                const float Ajk1_real = (((const float *)A)[2 * (j1 * lda + k)]);
                const float Ajk1_imag = (((const float *)A)[2 * (j1 * lda + k) + 1]);
                temp_real_1 += Aik_real * Ajk1_real - Aik_imag * Ajk1_imag;
                temp_imag_1 += Aik_real * Ajk1_imag + Aik_imag * Ajk1_real;
            }
        }

        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real_0 - alpha_imag * temp_imag_0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag_0 + alpha_imag * temp_real_0;

        if (j1 < N) {
            (((float *)C)[2 * (i * ldc + j1)]) += alpha_real * temp_real_1 - alpha_imag * temp_imag_1;
            (((float *)C)[2 * (i * ldc + j1) + 1]) += alpha_real * temp_imag_1 + alpha_imag * temp_real_1;
        }
    }
}
}
