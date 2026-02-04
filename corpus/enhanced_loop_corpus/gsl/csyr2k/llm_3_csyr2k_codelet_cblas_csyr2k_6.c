#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
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
    for (i = j; i < N; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const int A_ik_idx = 2 * (i * lda + k);
            const int B_jk_idx = 2 * (j * ldb + k);
            const int A_jk_idx = 2 * (j * lda + k);
            const int B_ik_idx = 2 * (i * ldb + k);
            const float Aik_real = (((const float *)A)[A_ik_idx]);
            const float Aik_imag = (((const float *)A)[A_ik_idx + 1]);
            const float Bik_real = (((const float *)B)[B_ik_idx]);
            const float Bik_imag = (((const float *)B)[B_ik_idx + 1]);
            const float Ajk_real = (((const float *)A)[A_jk_idx]);
            const float Ajk_imag = (((const float *)A)[A_jk_idx + 1]);
            const float Bjk_real = (((const float *)B)[B_jk_idx]);
            const float Bjk_imag = (((const float *)B)[B_jk_idx + 1]);
            temp_real += ((Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag));
            temp_imag += ((Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real));
        }
        const int C_idx = 2 * (i * ldc + j);
        (((float *)C)[C_idx]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[C_idx + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
