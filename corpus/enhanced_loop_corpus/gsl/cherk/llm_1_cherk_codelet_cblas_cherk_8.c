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
        float temp_real[2] = {0., 0.};
        float temp_imag[2] = {0., 0.};
        for (k = 0; k < K; k++) {
            for (int ii = 0; ii < 2 && (i + ii) < N; ii++) {
                const float Aki_real = (((const float *)A)[2 * (k * lda + i + ii)]);
                const float Aki_imag = -(((const float *)A)[2 * (k * lda + i + ii) + 1]);
                const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
                const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
                temp_real[ii] += Aki_real * Akj_real - Aki_imag * Akj_imag;
                temp_imag[ii] += Aki_real * Akj_imag + Aki_imag * Akj_real;
            }
        }
        for (int ii = 0; ii < 2 && (i + ii) < N; ii++) {
            (((float *)C)[2 * ((i + ii) * ldc + j)]) += alpha * temp_real[ii];
            (((float *)C)[2 * ((i + ii) * ldc + j) + 1]) += alpha * temp_imag[ii];
        }
    }
}
}
