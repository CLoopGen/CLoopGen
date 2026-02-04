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
    float temp_real[256]; // Local accumulation array to break WAW across iterations
    float temp_imag[256];
    for (j = i; j < N; j++) {
        temp_real[j - i] = 0.f;
        temp_imag[j - i] = 0.f;
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real[j - i] += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag[j - i] += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        float final_real = alpha_real * temp_real[j - i] - alpha_imag * temp_imag[j - i];
        float final_imag = alpha_real * temp_imag[j - i] + alpha_imag * temp_real[j - i];
        (((float *)C)[2 * (i * ldc + j)]) += final_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += final_imag;
    }
}
}
