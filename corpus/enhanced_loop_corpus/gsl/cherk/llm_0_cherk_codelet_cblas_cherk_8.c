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
    for (k = 0; k < K; k++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        const float Aki_imag = -(((const float *)A)[2 * (k * lda + i) + 1]);
        for (j = 0; j <= i; j++) {
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            if (k == 0) {
                temp_real = 0.;
                temp_imag = 0.;
            }
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
            if (k == K - 1) {
                (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
                (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
            }
        }
    }
}
}
