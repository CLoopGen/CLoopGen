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
    for (j = i; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float *A_ptr = (const float *)A;
        for (k = 0; k < K; k++) {
            int idx_ik = 2 * (k * lda + i);
            int idx_jk = 2 * (k * lda + j);
            const float Aki_real = A_ptr[idx_ik];
            const float Aki_imag = A_ptr[idx_ik + 1];
            const float Akj_real = A_ptr[idx_jk];
            const float Akj_imag = A_ptr[idx_jk + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        float *C_ptr = (float *)C;
        int idx_ij = 2 * (i * ldc + j);
        C_ptr[idx_ij] += alpha_real * temp_real - alpha_imag * temp_imag;
        C_ptr[idx_ij + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
