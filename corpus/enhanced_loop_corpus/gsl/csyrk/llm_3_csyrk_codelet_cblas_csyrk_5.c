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
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const float *base_A = (const float *)A + 2 * (k * lda);
            const float Aki_real = base_A[2 * i];
            const float Aki_imag = base_A[2 * i + 1];
            const float Akj_real = base_A[2 * j];
            const float Akj_imag = base_A[2 * j + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        float *C_entry = (float *)C + 2 * (i * ldc + j);
        C_entry[0] += alpha_real * temp_real - alpha_imag * temp_imag;
        C_entry[1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
