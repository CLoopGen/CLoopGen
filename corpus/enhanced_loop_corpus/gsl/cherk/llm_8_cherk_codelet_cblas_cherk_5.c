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
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        float temp_real0 = 0., temp_real1 = 0.;
        float temp_imag0 = 0., temp_imag1 = 0.;
        for (k = 0; k < K; k += 2) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Aik1_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
            const float Aik1_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);

            temp_real0 += Aik0_real * Ajk_real - Aik0_imag * Ajk_imag;
            temp_imag0 += Aik0_real * Ajk_imag + Aik0_imag * Ajk_real;
            temp_real1 += Aik1_real * Ajk_real - Aik1_imag * Ajk_imag;
            temp_imag1 += Aik1_real * Ajk_imag + Aik1_imag * Ajk_real;

            if (k+1 < K) {
                const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
                const float Ajk1_imag = -(((const float *)A)[2 * (j * lda + k + 1) + 1]);
                temp_real0 += Aik0_real * Ajk1_real - Aik0_imag * Ajk1_imag;
                temp_imag0 += Aik0_real * Ajk1_imag + Aik0_imag * Ajk1_real;
                temp_real1 += Aik1_real * Ajk1_real - Aik1_imag * Ajk1_imag;
                temp_imag1 += Aik1_real * Ajk1_imag + Aik1_imag * Ajk1_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag0;
        if (i+1 < N) {
            (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha * temp_real1;
            (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha * temp_imag1;
        }
    }
}
}
