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
    for (j = 0; j <= i && j < N; j += 2) {
        float temp_real_0 = 0.;
        float temp_imag_0 = 0.;
        float temp_real_1 = 0.;
        float temp_imag_1 = 0.;
        int k_end = K - (K % 2);
        for (k = 0; k < k_end; k += 2) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
            const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);

            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
            const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
            const float Ajk1_imag = -(((const float *)A)[2 * (j * lda + k + 1) + 1]);

            temp_real_0 += Aik0_real * Ajk0_real - Aik0_imag * Ajk0_imag;
            temp_imag_0 += Aik0_real * Ajk0_imag + Aik0_imag * Ajk0_real;

            temp_real_1 += Aik1_real * Ajk1_real - Aik1_imag * Ajk1_imag;
            temp_imag_1 += Aik1_real * Ajk1_imag + Aik1_imag * Ajk1_real;
        }
        for (; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real_0 += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag_0 += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
            if (j + 1 < N) {
                const float Ajk1_real = (((const float *)A)[2 * ((j+1) * lda + k)]);
                const float Ajk1_imag = -(((const float *)A)[2 * ((j+1) * lda + k) + 1]);
                temp_real_1 += Aik_real * Ajk1_real - Aik_imag * Ajk1_imag;
                temp_imag_1 += Aik_real * Ajk1_imag + Aik_imag * Ajk1_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real_0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_0;
        if (j + 1 < N) {
            (((float *)C)[2 * (i * ldc + j + 1)]) += alpha * temp_real_1;
            (((float *)C)[2 * (i * ldc + j + 1) + 1]) += alpha * temp_imag_1;
        }
    }
}
}
