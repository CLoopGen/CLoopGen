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
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        float sum_real_local = 0.;
        float sum_imag_local = 0.;
        for (k = K - 1; k >= 0; k--) {  // Reverse loop order: introduces different loop-carried dependency direction (RAW becomes WAR in original terms)
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            // Accumulate in local variables to preserve associativity, but reverse traversal changes data flow timing
            sum_real_local += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            sum_imag_local += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        temp_real = sum_real_local;
        temp_imag = sum_imag_local;
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
