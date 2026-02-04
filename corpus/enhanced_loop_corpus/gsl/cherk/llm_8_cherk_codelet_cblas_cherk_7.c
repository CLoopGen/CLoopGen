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
    for (j = 0; j <= i; j++) {
        float temp_real_0 = 0.;
        float temp_imag_0 = 0.;
        float temp_real_1 = 0.;
        float temp_imag_1 = 0.;
        for (k = 0; k < K; k++) {
            const float Aik0_real = (((const float *)A)[2 * ((i+0) * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * ((i+0) * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real_0 += Aik0_real * Ajk_real - Aik0_imag * Ajk_imag;
            temp_imag_0 += Aik0_real * Ajk_imag + Aik0_imag * Ajk_real;

            if (i + 1 < N) {
                const float Aik1_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
                const float Aik1_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
                temp_real_1 += Aik1_real * Ajk_real - Aik1_imag * Ajk_imag;
                temp_imag_1 += Aik1_real * Ajk_imag + Aik1_imag * Ajk_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real_0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_0;
        if (i + 1 < N && j <= i + 1) {
            (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha * temp_real_1;
            (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha * temp_imag_1;
        }
    }
}
}
