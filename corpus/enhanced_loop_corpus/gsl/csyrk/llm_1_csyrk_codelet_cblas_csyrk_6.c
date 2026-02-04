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
        for (k = 0; k < K; k++) {
            int idx_i = 2 * (i * lda + k);
            int idx_j = 2 * (j * lda + k);
            const float Aik_real = ((const float*)A)[idx_i];
            const float Aik_imag = ((const float*)A)[idx_i + 1];
            const float Ajk_real = ((const float*)A)[idx_j];
            const float Ajk_imag = ((const float*)A)[idx_j + 1];
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        int idx_c = 2 * (i * ldc + j);
        ((float*)C)[idx_c]     += alpha_real * temp_real - alpha_imag * temp_imag;
        ((float*)C)[idx_c + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
