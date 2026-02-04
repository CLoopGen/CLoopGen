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
    for (j = 0; j <= i; j += 2) {
        float temp_real_0 = 0.;
        float temp_imag_0 = 0.;
        float temp_real_1 = 0.;
        float temp_imag_1 = 0.;
        int j1 = j + 1;
        int update_j1 = (j1 <= i);
        for (k = 0; k < K; k++) {
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = -(((const float *)A)[2 * (k * lda + i) + 1]);

            const float Akj0_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj0_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            temp_real_0 += Aki_real * Akj0_real - Aki_imag * Akj0_imag;
            temp_imag_0 += Aki_real * Akj0_imag + Aki_imag * Akj0_real;

            if (update_j1) {
                const float Akj1_real = (((const float *)A)[2 * (k * lda + j1)]);
                const float Akj1_imag = (((const float *)A)[2 * (k * lda + j1) + 1]);
                temp_real_1 += Aki_real * Akj1_real - Aki_imag * Akj1_imag;
                temp_imag_1 += Aki_real * Akj1_imag + Aki_imag * Akj1_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real_0;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_0;
        if (update_j1) {
            (((float *)C)[2 * (i * ldc + j1)]) += alpha * temp_real_1;
            (((float *)C)[2 * (i * ldc + j1) + 1]) += alpha * temp_imag_1;
        }
    }
}
}
